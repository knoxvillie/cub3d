/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:22:56 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/02/20 21:45:05 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	check_limits(t_data *img, int x, int y)
{
	if (x < img->w_img && x > 0 && y < img->h_img && y > 0)
		return (1);
	else
		return (0);
}

void	draw_points(t_data *img, t_iso_res res0, t_iso_res res1, t_color c)
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	int		pixels;

	dx = (float)res1.x - (float)res0.x;
	dy = (float)res1.y - (float)res0.y;
	pixels = sqrt((dx * dx) + (dy * dy));
	c.step = (c.c1 - c.c0) / (pixels - 1);
	dx /= pixels;
	dy /= pixels;
	x = res0.x;
	y = res0.y;
	while (pixels > 0)
	{
		if (check_limits(img, (int)x, (int)y))
			my_mlx_pixel_put(img, (int)x, (int)y, (int)c.c0);
		x += dx;
		y += dy;
		c.c0 += c.step;
		pixels = pixels - 1;
	}
}
