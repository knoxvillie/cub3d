/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:25:56 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:28:08 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*#include<stdio.h>
#include<string.h>
int	main(void)
{
	char	name[] = "fabio valli vieira";
	char	name1[] = "fabio valli vieira";
	printf("%s\n",(unsigned char*)ft_memset(name, 1, 5));
	printf("%s\n",(unsigned char*)ft_memset(name1, 1, 5));
	return (0);
}*/
