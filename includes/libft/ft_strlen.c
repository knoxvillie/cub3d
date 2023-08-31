/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:34:56 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 13:04:24 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
/*#include<stdio.h>
#include<string.h>
int	main(void)
{
	printf("%zu\n", ft_strlen("fabio"));
	printf("%zu\n", strlen("fabio"));
	printf("%zu\n", ft_strlen(""));
	printf("%zu\n", strlen(""));
	return (0);
}*/
