/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:57:36 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/10 09:45:29 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	else
		return (0);
}
/*#include<stdio.h>
#include<ctype.h>
int	main(void)
{
	printf("%d\n",ft_isalpha('a'));
	printf("%d\n",isalpha('a'));
	printf("%d\n",ft_isalpha('2'));
	printf("%d\n",isalpha('2'));
	printf("%d\n",ft_isalpha('Ä'));
	printf("%d\n",isalpha('Ä'));
}*/
