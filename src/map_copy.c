/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:07:26 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/21 11:07:28 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

static void	ft_handle_copy_2(t_copy *this)
{
	int	tab_size;

	tab_size = TABSIZE;
	(*this->j)++;
	while (tab_size)
	{
		this->dst[(*this->i)++] = '#';
		tab_size--;
	}
}

static void	ft_handle_copy_1(t_copy *this)
{
	if (!this->r_wall && this->src[*this->j] == '\t')
		ft_handle_copy_2(this);
	if (!this->r_wall && (this->src[*this->j] == '1'
			|| this->src[*this->j] == '0'))
		this->r_wall = true;
	if (!this->r_wall && this->src[*this->j] == ' ')
	{
		this->dst[(*this->i)++] = '#';
		(*this->j)++;
		return ;
	}
	if (this->r_wall && this->src[*this->j] == ' ')
	{
		this->dst[(*this->i)++] = '1';
		(*this->j)++;
		return ;
	}
	this->dst[(*this->i)++] = this->src[(*this->j)++];
}

static void	ft_handle_copy(t_data *data, char *src, char *dst)
{
	int		i;
	int		j;
	t_copy	this;

	i = 1;
	j = 0;
	this.r_wall = false;
	this.src = src;
	this.dst = dst;
	this.i = &i;
	this.j = &j;
	dst[0] = '#';
	dst[data->bg_line + 2] = '\0';
	while (src[j] && src[j] != '\n')
		ft_handle_copy_1(&this);
	while (i < (data->bg_line + 2))
		dst[i++] = '#';
}

void	ft_handle_map_cp(t_data *data)
{
	int		i;
	int		map_start;
	char	*line;

	i = 0;
	map_start = data->map_start;
	data->map_cp = (char **)malloc(sizeof(char *) * (data->bg_column + 1 + 2));
	line = (char *)malloc(sizeof(char) * (data->bg_line + 1 + 2));
	data->map_cp[i++] = ft_first_last_line(line, data->bg_line + 1 + 2);
	while (data->file_map[map_start])
	{
		line = (char *)malloc(sizeof(char) * (data->bg_line + 1 + 2));
		ft_handle_copy(data, data->file_map[map_start], line);
		data->map_cp[i++] = line;
		map_start++;
	}
	line = (char *)malloc(sizeof(char) * (data->bg_line + 1 + 2));
	data->map_cp[i++] = ft_first_last_line(line, data->bg_line + 1 + 2);
	data->map_cp[i] = NULL;
}
