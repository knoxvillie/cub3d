/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:43:58 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/27 16:56:44 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

/* side y = 1 and side x = 0 */
void	get_wall_dir(t_data *img)
{
	if (img->side == 1)
	{
		if (img->raydir_y < 0)
		{
			img->dirwall = NORTH;
		}
		else
		{
			img->dirwall = SOUTH;
		}
	}
	else
	{
		if (img->raydir_x > 0)
		{
			img->dirwall = EAST;
		}
		else
		{
			img->dirwall = WEST;
		}
	}
}

float	get_color_rgb(int R, int G, int B)
{
	return (((R) << 16) + ((G) << 8) + (B));
}

/* calculate ray position and direction
which box of the map we're in
length of ray from one x or y-side to next x or y-side
what direction to step in x or y-direction (either +1 or -1)
 img->stepx;
 img->stepy; */
void	init_ray(t_data *img, int x)
{
	img->camera_x = 2 * x / (float)img->w_img - 1;
	img->raydir_x = img->dir_x + img->plane_x * img->camera_x;
	img->raydir_y = img->dir_y + img->plane_y * img->camera_x;
	img->map_x = (int)img->pos_x;
	img->map_y = (int)img->pos_y;
	if (img->raydir_x == 0)
		img->deltadistx = 1e30;
	else
		img->deltadistx = fabs(1 / img->raydir_x);
	if (img->raydir_y == 0)
		img->deltadisty = 1e30;
	else
		img->deltadisty = fabs(1 / img->raydir_y);
}

/* calculate step and initial sideDist */
void	config_dda(t_data *img)
{
	img->hit = 0;
	if (img->raydir_x < 0)
	{
		img->stepx = -1;
		img->sidedistx = (img->pos_x - img->map_x) * img->deltadistx;
	}
	else
	{
		img->stepx = 1;
		img->sidedistx = (img->map_x + 1.0 - img->pos_x) * img->deltadistx;
	}
	if (img->raydir_y < 0)
	{
		img->stepy = -1;
		img->sidedisty = (img->pos_y - img->map_y) * img->deltadisty;
	}
	else
	{
		img->stepy = 1;
		img->sidedisty = (img->map_y + 1.0 - img->pos_y) * img->deltadisty;
	}
}

/* perform DDA
jump to next map square, either in x-direction, or in y-direction
x side of the wall
y side of the wall
Check if ray has img->hit a wall */
void	dda_algorithm(t_data *img)
{
	while (img->hit == 0)
	{
		if (img->sidedistx < img->sidedisty)
		{
			img->sidedistx += img->deltadistx;
			img->map_x += img->stepx;
			img->side = 0;
		}
		else
		{
			img->sidedisty += img->deltadisty;
			img->map_y += img->stepy;
			img->side = 1;
		}
		if (img->map_cp[img->map_y][img->map_x] == '1')
			img->hit = 1;
	}
}
