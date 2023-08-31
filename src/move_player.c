/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:01:03 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/08/27 14:59:45 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

/* Direction vector
0.0349 rad = 2 degrees
rotate aroung origin in 2 degrees
plane vector
0.0349 rad = 2 degrees
rotate aroung origin in 2 degrees */
void	rotate_vec(t_data *img, int side)
{
	t_iso_res	rot_dir;
	t_iso_res	rot_plane;
	float		angle;

	if (side)
		angle = 0.0349;
	else
		angle = -0.0349;
	rot_dir.x = img->dir_x * cos(angle) - img->dir_y * sin(angle);
	rot_dir.y = img->dir_x * sin(angle) + img->dir_y * cos(angle);
	img->dir_x = rot_dir.x;
	img->dir_y = rot_dir.y;
	rot_plane.x = img->plane_x * cos(angle) - img->plane_y * sin(angle);
	rot_plane.y = img->plane_x * sin(angle) + img->plane_y * cos(angle);
	img->plane_x = rot_plane.x;
	img->plane_y = rot_plane.y;
}

/* side == 1 -> forward | side == 0 -> backward
Direction vector */
void	move_for_back_vec(t_data *img, int side)
{
	int		signal;
	float	tmp_x;
	float	tmp_y;

	tmp_x = img->pos_x;
	tmp_y = img->pos_y;
	if (side)
		signal = 1;
	else
		signal = -1;
	img->pos_x = img->pos_x + (signal) * img->dir_x * 0.035;
	img->pos_y = img->pos_y + (signal) * img->dir_y * 0.035;
	check_wall_hit (img, tmp_x, tmp_y);
}

/* angle = M_PI / 2; // rotate the direction of 90 degrees or - 90 degrees
side == 1 -> right | side == 0 -> left
right(side = 1)
apply - 90 degrees on rot matrix and sum to the pos_x
left(side = 0)
apply 90 degrees on rot matrix and sum to the pos_x */
void	move_right_left_vec(t_data *img, int side)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = img->pos_x;
	tmp_y = img->pos_y;
	if (side)
	{
		img->pos_x += img->dir_y * 0.035;
		img->pos_y += -img->dir_x * 0.035;
	}
	else
	{
		img->pos_x += -img->dir_y * 0.035;
		img->pos_y += img->dir_x * 0.035;
	}
	check_wall_hit (img, tmp_x, tmp_y);
}

void	check_wall_hit(t_data *img, float tmp_x, float tmp_y)
{
	if (img->map_cp[(int)img->pos_y][(int)img->pos_x] == '1')
	{
		img->pos_y = tmp_y;
		img->pos_x = tmp_x;
	}
}

int	op_move(t_data *img)
{
	if (img->up)
		move_for_back_vec(img, 1);
	if (img->down)
		move_for_back_vec(img, 0);
	if (img->left)
		move_right_left_vec(img, 1);
	if (img->right)
		move_right_left_vec(img, 0);
	if (img->rotleft)
		rotate_vec(img, 0);
	if (img->rotright)
		rotate_vec(img, 1);
	if (img->rotright || img->rotleft || img->right
		|| img->left || img->up || img->down)
		return (1);
	else
		return (0);
}
