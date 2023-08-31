/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:31:30 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:31:30 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*#include<stdio.h>
#include<unistd.h>
void	ft_printc(unsigned int i, char *c)
{
	write(1, &c[i], 1);
}
int	main(void)
{
	char	*str = "f@bi0 VALLI VIEira";
	char	*res;
	ft_striteri(str,&ft_printc);
	return (0);
}*/
