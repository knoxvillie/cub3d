/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:56 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/31 15:36:48 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

void	ft_free_table(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	while (table[i])
	{
		free (table[i]);
		i++;
	}
	free (table);
}

static void	ft_free_data_print_exit_1(t_data *data)
{
	if (data->rgb)
		ft_free_table(data->rgb);
	if (data->generic)
		ft_free_table(data->generic);
	if (data->elements)
		ft_free_table(data->elements);
	if (data->file_map)
		ft_free_table(data->file_map);
	if (data->map_cp)
		ft_free_table(data->map_cp);
	if (data->map_flood)
		ft_free_table(data->map_flood);
}

void	ft_free_data_print_exit(t_data *data, char *msg)
{
	ft_free_data_print_exit_1(data);
	if (data->line)
		free (data->line);
	if (data->no_vptr)
		mlx_destroy_image(data->mlx, data->no_vptr);
	if (data->so_vptr)
		mlx_destroy_image(data->mlx, data->so_vptr);
	if (data->we_vptr)
		mlx_destroy_image(data->mlx, data->we_vptr);
	if (data->ea_vptr)
		mlx_destroy_image(data->mlx, data->ea_vptr);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free (data->mlx);
	}
	ft_putstr_fd(msg, STDERR_FILENO);
	exit (1);
}

void	ft_free_data(t_data *data)
{
	if (data->line)
		free (data->line);
	if (data->rgb)
		ft_free_table(data->rgb);
	if (data->generic)
		ft_free_table(data->generic);
	if (data->elements)
		ft_free_table(data->elements);
	if (data->file_map)
		ft_free_table(data->file_map);
	if (data->map_cp)
		ft_free_table(data->map_cp);
	if (data->map_flood)
		ft_free_table(data->map_flood);
}

void	ft_free_tex(t_data *data)
{
	int	i;

	i = 0;
	if (!data->tex)
		return ;
	while (i < 4)
	{
		free (data->tex[i]);
		i++;
	}
	free (data->tex);
	mlx_destroy_image(data->mlx, data->no_ptr.img);
	mlx_destroy_image(data->mlx, data->so_ptr.img);
	mlx_destroy_image(data->mlx, data->we_ptr.img);
	mlx_destroy_image(data->mlx, data->ea_ptr.img);
}
