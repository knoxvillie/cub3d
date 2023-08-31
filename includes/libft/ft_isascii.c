/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:49:21 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/10 09:45:40 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*#include<stdio.h>
#include<ctype.h>
int	main(void)
{
	printf("%d\n",ft_isascii('8'));
	printf("%d\n",isascii('8'));
	printf("%d\n",ft_isascii('a'));
	printf("%d\n",isascii('a'));
	printf("%d\n",ft_isascii(8));
	printf("%d\n",isascii(8));
	printf("%d\n",'ü');
	printf("%d\n",ft_isascii(128));
	printf("%d\n",isascii(128));
}*/
