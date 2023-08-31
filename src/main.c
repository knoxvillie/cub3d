/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:43:58 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/27 14:59:27 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

int	ft_close(t_data *vars)
{
	ft_free_data(vars);
	ft_free_tex(vars);
	if (vars)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit (EXIT_SUCCESS);
}

int	render_next_frame(t_data *data)
{
	if (!op_move(data))
		return (0);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	draw_raycaster(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_putstr_fd("Error\nWrong num of args\n", STDERR_FILENO), 1);
	init_data_structure(&data, argv[1]);
	ft_validation(&data);
	init_data(&data);
	draw_raycaster(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, DestroyNotify, NoEventMask, ft_close, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, deal_key_press, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, deal_key_release, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	ft_putstr_fd("\n\n>>> VALIDATION OK! <<<\n", 1);
	return (0);
}
