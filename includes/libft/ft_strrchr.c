/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:35:53 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:35:53 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
/*#include<stdio.h>
#include <string.h>
int	main(void)
{
	char *str = "fbaibio";

	printf("%s \n", ft_strrchr(str, 'i'));
	printf("%s \n", ft_strrchr(str, 'b'));
	printf("%s \n", ft_strrchr(str, 'g'));
	printf("%s \n", ft_strrchr(str, '\0'));
	printf("%s \n", strrchr(str, 'i'));
	printf("%s \n", strrchr(str, 'b'));
	printf("%s \n", strrchr(str, 'g'));
	printf("%s \n", strrchr(str, '\0'));
	return(0);
}*/
