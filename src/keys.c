/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:01:03 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/08/27 15:04:53 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

int	check_keys_press(int key, t_data *img)
{
	if (key == ESC)
		ft_close(img);
	if (key == UP || key == DOWN || key == LEFT
		|| key == RIGHT || key == ROTRIGHT || key == ROTLEFT)
		op_move_press(key, img);
	else
		return (0);
	return (1);
}

int	check_keys_release(int key, t_data *img)
{
	if (key == ESC)
		ft_close(img);
	if (key == UP || key == DOWN || key == LEFT
		|| key == RIGHT || key == ROTRIGHT || key == ROTLEFT)
		op_move_release(key, img);
	else
		return (0);
	return (1);
}

int	deal_key_press(int key, void *data)
{
	t_data	*img;

	img = (t_data *)data;
	if (!check_keys_press(key, img))
		return (0);
	return (0);
}

int	deal_key_release(int key, void *data)
{
	t_data	*img;

	img = (t_data *)data;
	if (!check_keys_release(key, img))
		return (0);
	return (0);
}
