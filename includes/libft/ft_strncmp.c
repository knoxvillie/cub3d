/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:35:36 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:35:36 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*#include<stdio.h>
#include<string.h>
int main(void)
{
    char leftStr[] = "test\200";
    char rightStr[] = "test\0";
    int n = 6;

    // char leftStr[] = "hfgh";
    // char rightStr[] = "hfghhhhhhhhh";
    // int n = 1;

    int res = ft_strncmp(leftStr, rightStr, n);
	int res1 = strncmp(leftStr, rightStr, n);

    if (res==0)
        printf("Strings are equal");
    else
        printf("Strings are unequal");

    printf("\nValue returned by strcmp() is:  %d\n" , res);

    if (res1==0)
        printf("Strings are equal");
    else
        printf("Strings are unequal");

    printf("\nValue returned by strcmp() is:  %d\n" , res1);


    return 0;
}*/
