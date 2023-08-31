/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:30:46 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:30:46 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}
/*#include<stdio.h>
#include <string.h>
int	main(void)
{
	char *str = "fabio";

	printf("%s \n", ft_strchr(str, 'i'));
	printf("%s \n", ft_strchr(str, 'b'));
	printf("%s \n", ft_strchr(str, 'g'));
	printf("%s \n", ft_strchr(str, '\0'));
	printf("%s \n", strchr(str, 'i'));
	printf("%s \n", strchr(str, 'b'));
	printf("%s \n", strchr(str, 'g'));
	printf("%s \n", strchr(str, '\0'));
	return(0);
}*/
