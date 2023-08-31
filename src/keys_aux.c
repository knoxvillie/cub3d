/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:01:03 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/08/27 15:01:13 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

void	op_move_press(int key, t_data *img)
{
	if (key == UP)
		img->up = 1;
	if (key == DOWN)
		img->down = 1;
	if (key == LEFT)
		img->left = 1;
	if (key == RIGHT)
		img->right = 1;
	if (key == ROTLEFT)
		img->rotleft = 1;
	if (key == ROTRIGHT)
		img->rotright = 1;
}

void	op_move_release(int key, t_data *img)
{
	if (key == UP)
		img->up = 0;
	if (key == DOWN)
		img->down = 0;
	if (key == LEFT)
		img->left = 0;
	if (key == RIGHT)
		img->right = 0;
	if (key == ROTLEFT)
		img->rotleft = 0;
	if (key == ROTRIGHT)
		img->rotright = 0;
}
