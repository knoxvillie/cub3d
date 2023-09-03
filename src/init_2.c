/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:43:58 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/03 14:54:22 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

int	*get_addr_tex_img(t_data *img, t_teximg *dir_ptr)
{
	int			*tmp;
	int			x;
	int			y;

	tmp = (int *)malloc(sizeof(int) * img->tex_h * img->tex_w);
	if (!tmp)
		return (NULL);
	dir_ptr->addr = (int *)mlx_get_data_addr(dir_ptr->img, &(dir_ptr->bpp),
			&(dir_ptr->line_l), &(dir_ptr->endian));
	y = 0;
	while (y < img->tex_h)
	{
		x = 0;
		while (x < img->tex_w)
		{
			tmp[y * img->tex_w + x] = dir_ptr->addr[y * img->tex_w + x];
			x++;
		}
		y++;
	}
	return (tmp);
}

void	init_tex(t_data *img)
{
	img->tex = (int **)malloc(4 * sizeof(int *));
	if (!img->tex)
		exit (1);
	img->no_ptr.img = img->no_vptr;
	img->so_ptr.img = img->so_vptr;
	img->we_ptr.img = img->we_vptr;
	img->ea_ptr.img = img->ea_vptr;
	img->tex[NORTH] = get_addr_tex_img(img, &img->so_ptr);
	img->tex[SOUTH] = get_addr_tex_img(img, &img->no_ptr);
	img->tex[WEST] = get_addr_tex_img(img, &img->ea_ptr);
	img->tex[EAST] = get_addr_tex_img(img, &img->we_ptr);
}

/* fov(field of view) is the value which represents
the Field of Vision . For 1 is 90 degrees. */
void	init_data(t_data *data)
{
	data->w_img = 1920;
	data->h_img = 1080;
	data->mlx_win = mlx_new_window(data->mlx, data->w_img,
			data->h_img, "cub3D");
	data->img = mlx_new_image(data->mlx, data->w_img, data->h_img);
	data->addr = NULL;
	data->w_map = data->bg_line;
	data->h_map = data->bg_column;
	data->fov = 1;
	init_dir(data);
	data->pos_x = data->p_posx;
	data->pos_y = data->p_posy;
	data->tex_h = 64;
	data->tex_w = 64;
	init_tex(data);
	data->left = 0;
	data->right = 0;
	data->up = 0;
	data->down = 0;
	data->rotleft = 0;
	data->rotright = 0;
	data->addr = mlx_get_data_addr(data->img, &(data->bpp), &(data->line_l),
			&(data->endian));
}
