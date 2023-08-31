/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:32:08 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:34:44 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}
/*#include <stdio.h>
int	main(void)
{
    char str1[] = "FabioValli";
    int n = 5;
    int length;
      char str2[20] = "";



    printf("%s \n", str1);
    printf("%s \n", str2);
    printf("%d \n", n);
    length = ft_strlcpy(str2,str1,n);
    printf("%d \n", length);
    printf("%s \n", str1);
    printf("%s \n", str2);
    return(0);
}*/
