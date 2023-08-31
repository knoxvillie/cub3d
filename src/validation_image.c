/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:14:19 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/26 13:50:35 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

void	*ft_load_image(t_data *data, char *file)
{
	void	*image;

	file[((int)ft_strlen(file)) - 1] = '\0';
	image = mlx_xpm_file_to_image(data->mlx, file,
			&data->tex_w, &data->tex_h);
	if (!image)
		ft_free_data_print_exit(data, "Error\n Failed to load an image\n");
	return (image);
}

static void	ft_check_rgb(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->rgb[i])
	{
		j = 0;
		while (data->rgb[i][j])
		{
			if ((j != 0) && data->rgb[i][j] == '\n')
			{
				j++;
				continue ;
			}
			if (!ft_isdigit(data->rgb[i][j]))
				ft_free_data_print_exit(data, "Error\nInvalid RGB input\n");
			j++;
		}
		i++;
	}
}

static bool	ft_validation_rbg_range(t_data *data)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(data->rgb[0]);
	g = ft_atoi(data->rgb[1]);
	b = ft_atoi(data->rgb[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (false);
	if (ft_abs_compare("F", data->generic[0]))
	{
		data->f_r = (unsigned char)r;
		data->f_g = (unsigned char)g;
		data->f_b = (unsigned char)b;
	}
	else if (ft_abs_compare("C", data->generic[0]))
	{
		data->c_r = (unsigned char)r;
		data->c_g = (unsigned char)g;
		data->c_b = (unsigned char)b;
	}
	return (true);
}

void	ft_validation_fc_rgb(t_data *data)
{
	int		i;

	data->rgb = ft_split(data->generic[1], ',');
	i = 0;
	while (data->rgb && data->rgb[i])
		i++;
	if (i != 3)
		ft_free_data_print_exit(data, "Error\nInvalid RBG input\n");
	ft_check_rgb(data);
	if (!(ft_validation_rbg_range(data)))
		ft_free_data_print_exit(data, "Error\nInvalid RBG range of input\n");
	ft_free_table(data->rgb);
	data->rgb = NULL;
}
