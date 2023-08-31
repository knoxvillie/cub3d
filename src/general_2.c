/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:35:53 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/27 19:01:29 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

int	ft_real_size(char *str)
{
	int		size;
	bool	r_wall;

	size = 0;
	if (!str)
		return (size);
	r_wall = false;
	while (*str != '\0' && *str != '\n')
	{
		if ((*str == '1' || *str == '0') && !r_wall)
			r_wall = true;
		if (*str == '\t' && !r_wall)
			size += TABSIZE;
		else
			size++;
		str++;
	}
	return (size);
}
