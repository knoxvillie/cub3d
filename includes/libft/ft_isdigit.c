/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:07:53 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/10 09:45:50 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	else
		return (0);
}
/*#include<stdio.h>
#include<ctype.h>
int	main(void)
{
	printf("%d\n",ft_isdigit('8'));
	printf("%d\n",isdigit('8'));
	printf("%d\n",ft_isdigit('a'));
	printf("%d\n",isdigit('a'));
	printf("%d\n",ft_isdigit(8));
	printf("%d\n",isdigit(8));
}*/
