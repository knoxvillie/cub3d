/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:14:09 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/09 09:37:26 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest || src)
	{
		if (dest > src)
		{
			while (n--)
			{
				((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
			}
		}
		else
		{
			while (n--)
			{
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
				i++;
			}
		}
	}
	return (dest);
}
/*#include<stdio.h>
#include<string.h>
int     main(void)
{
        char    src[] = "fabio vieira";
        char    dest[] = "vieira fabio";
        char    src1[] = "fabio vieira";
        char    dest1[] = "vieira fabio";
        char    src2[100] = "0123456789";
        char    src22[100] = "0123456789";
        ft_memmove(dest, src, 13);
        memmove(dest1, src1, 13);
        ft_memmove(src2+5, src2, 10);
        memmove(src22+5, src22, 20);
        printf("%s\n", dest);
        printf("%s\n", dest1);
        printf("%s\n", src2); //nesse caso o dado do src
	//se altera ja q as memorias se sobrepoem
        printf("%s\n", src22);
        return (0);
}*/
