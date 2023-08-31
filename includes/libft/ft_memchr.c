/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:11:24 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:11:37 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/*#include<stdio.h>
#include <string.h>
int	main(void)
{
	char *str = "fabiovallivieira";
	int	n = 10;

	printf("%s \n", (char *)ft_memchr(str, 'v', n));
	printf("%s \n", (char *)ft_memchr(str, 'b', n));
	printf("%s \n", (char *)ft_memchr(str, 'g', n));
	printf("%s \n", (char *)ft_memchr(str, '\0', n));
	printf("%s \n", (char *)memchr(str, 'v', n));
	printf("%s \n", (char *)memchr(str, 'b', n));
	printf("%s \n", (char *)memchr(str, 'g', n));
	printf("%s \n", (char *)memchr(str, '\0', n));
	return(0);
}*/
