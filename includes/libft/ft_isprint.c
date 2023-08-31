/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:03:25 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/10 09:46:02 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (16384);
	else
		return (0);
}
/*#include<stdio.h>
#include<ctype.h>
int	main(void)
{
	printf("%d\n",ft_isprint('9'));
	printf("%d\n",isprint('9'));
	printf("%d\n",ft_isprint('a'));
	printf("%d\n",isprint('a'));
	printf("%d\n",ft_isprint('\n'));
	printf("%d\n",isprint('\n'));
	return (0);
}*/
