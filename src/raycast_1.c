/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:43:58 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/27 16:57:07 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

/* perpendicular distance from camera plane to the wall
img->perpwalldist;
hit x side of the wall and calculate perpwalldist
hit y side of the wall and calculate perpwalldist
Calculate height of line to raw on screen
calculate lowest and highest pixel to fill in current stripe */
void	calc_vert_line_draw(t_data *img)
{
	if (img->side == 0)
		img->perpwalldist = (img->sidedistx - img->deltadistx);
	else
		img->perpwalldist = (img->sidedisty - img->deltadisty);
	if (img->perpwalldist != 0)
		img->lineheight = (int)(img->h_img / img->perpwalldist);
	else
		img->lineheight = img->h_img;
	img->drawstart = -img->lineheight / 2 + img->h_img / 2;
	if (img->drawstart < 0)
		img->drawstart = 0;
	img->drawend = img->lineheight / 2 + img->h_img / 2;
	if (img->drawend >= img->h_img)
		img->drawend = img->h_img - 1;
}

/* x coordinate on the tex
How much to increase the tex coordinate per screen pixel
Starting tex coordinate */
void	update_tex(t_data *img, int h)
{
	if (img->side == 0)
		img->wallhit = img->pos_y + img->perpwalldist * img->raydir_y;
	else
		img->wallhit = img->pos_x + img->perpwalldist * img->raydir_x;
	img->wallhit -= floor((img->wallhit));
	img->tex_x = (int)(img->wallhit * (float)img->tex_w);
	if (img->dirwall == SOUTH)
		img->tex_x = img->tex_w - img->tex_x - 1;
	img->tex_step = 1.0 * img->tex_w / img->lineheight;
	img->tex_pos = (img->drawstart - h / 2 + img->lineheight / 2);
	img->tex_pos *= img->tex_step;
}

void	draw_tex(t_data *img, int x)
{
	int	z;
	int	color;

	z = img->drawstart;
	while (z < img->drawend)
	{
		img->tex_y = (int)img->tex_pos & (img->tex_w - 1);
		img->tex_pos += img->tex_step;
		color = img->tex[img->dirwall][img->tex_h * img->tex_y + img->tex_x];
		my_mlx_pixel_put(img, (int)x, (int)z, (int)color);
		z++;
	}
}

void	draw_raycaster(t_data *img)
{
	int	h;
	int	x;

	h = img->h_img;
	x = 0;
	while (x < img->w_img)
	{
		init_ray(img, x);
		config_dda(img);
		dda_algorithm(img);
		calc_vert_line_draw(img);
		get_wall_dir(img);
		update_tex(img, h);
		draw_tex(img, x);
		img->floorcolor = get_color_rgb(img->f_r, img->f_g, img->f_b);
		img->ceilingcolor = get_color_rgb(img->c_r, img->c_g, img->c_b);
		draw_points(img, (t_iso_res){x, 0, 0}, (t_iso_res){x, img->drawstart,
			0}, (t_color){img->ceilingcolor, img->ceilingcolor, 0});
		draw_points(img, (t_iso_res){x, img->drawend, 0}, (t_iso_res){x, h,
			0}, (t_color){img->floorcolor, img->floorcolor, 0});
		x++;
	}
}
