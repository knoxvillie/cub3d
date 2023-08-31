/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:02:16 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 13:02:16 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
/*#include<stdio.h>
int	main(void)
{
	char c = 'A';
    char c1 = 'c';
    char c2 = ' ';
    char c3 = '1';

    printf("%c \n", ft_tolower(c));
	printf("%c \n", ft_tolower(c1));
	printf("%c \n", ft_tolower(c2));
    printf("%c \n", ft_tolower(c3));

	return(0);
}*/
