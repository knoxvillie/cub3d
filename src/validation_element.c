/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:59:22 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/01 20:34:04 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

static void	ft_handle_element(t_data *data, char *line)
{
	int		i;

	i = 0;
	data->generic = ft_split(line, ' ');
	while (data->generic && data->generic[i])
		i++;
	if (i != 2)
		ft_free_data_print_exit(data, "Error\nSomething is wrong with map\n");
	i = 0;
	while (data->elements[i]
		&& !ft_abs_compare(data->generic[0], data->elements[i]))
		i++;
	if (data->elements[i] == NULL)
		ft_free_data_print_exit(data, "Error\nInvalid map element\n");
	if (data->magic[i] != 0)
		ft_free_data_print_exit(data, "Error\nMap elements must not repeat\n");
	data->magic[i] = 1;
	ft_free_table(data->generic);
	data->generic = NULL;
}

void	ft_check_map_elements(t_data *data)
{
	int	i;

	i = 0;
	while (data->file_map[i])
	{
		if (ft_element_done(data->magic))
			return ;
		if (ft_is_line_space(data->file_map[i]))
		{
			i++;
			continue ;
		}
		if ((i == data->map_start) && !ft_element_done(data->magic))
			ft_free_data_print_exit(data, "Error\nInvalid map elements\n");
		ft_handle_element(data, data->file_map[i]);
		i++;
	}
}

static void	ft_check_init_elements(t_data *data)
{
	if (ft_abs_compare("NO", data->generic[0]))
		data->no_vptr = ft_load_image(data, data->generic[1]);
	else if (ft_abs_compare("SO", data->generic[0]))
		data->so_vptr = ft_load_image(data, data->generic[1]);
	else if (ft_abs_compare("WE", data->generic[0]))
		data->we_vptr = ft_load_image(data, data->generic[1]);
	else if (ft_abs_compare("EA", data->generic[0]))
		data->ea_vptr = ft_load_image(data, data->generic[1]);
	else if (ft_abs_compare(data->generic[0], "F")
		|| ft_abs_compare(data->generic[0], "C"))
		ft_validation_fc_rgb(data);
}

void	ft_check_value_elements(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->file_map[i])
	{
		if (ft_element_done(data->magic))
			return ;
		if (ft_is_line_space(data->file_map[i]))
		{
			i++;
			continue ;
		}
		j = 0;
		data->generic = ft_split(data->file_map[i], ' ');
		while (data->elements[j]
			&& !ft_abs_compare(data->generic[0], data->elements[j]))
			j++;
		data->magic[j] = 1;
		ft_check_init_elements(data);
		ft_free_table(data->generic);
		data->generic = NULL;
		i++;
	}
}
