/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:16:54 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/14 11:48:38 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

bool	ft_abs_compare(char *s1, char *s2)
{
	int	i;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	return (true);
}

bool	ft_is_line_space(char *str)
{
	if (!str)
		return (false);
	while (*str == ' ' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '\0')
		return (true);
	return (false);
}

bool	ft_reach_map(char *str)
{
	while (*str == ' ' || *str == '\f' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	if (*str != '1' && *str != '0')
		return (false);
	while (*str == '1' || *str == '0' || *str == ' ')
		str++;
	if (*str != '\n')
		return (false);
	return (true);
}

bool	ft_element_done(int *table)
{
	int	i;

	i = 0;
	while (i <= 5)
	{
		if (table[i] != 1)
			return (false);
		i++;
	}
	return (true);
}

char	*ft_first_last_line(char *line, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
		line[i++] = '#';
	line[i] = '\0';
	return (line);
}
