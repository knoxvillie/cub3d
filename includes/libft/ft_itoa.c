/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:52:32 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 11:55:18 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*nb;

	num = n;
	len = ft_itoa_len(num);
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (0);
	nb[len] = '\0';
	if (num == 0)
		nb[0] = '0';
	if (num < 0)
	{
		nb[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		nb[len - 1] = (num % 10) + 48;
		num = num / 10;
		len --;
	}
	return (nb);
}
/*#include<stdio.h>
int	main(void)
{
	printf("num =%d | string =%s\n", ft_itoa_len(0), ft_itoa(0));
	printf("num =%d | string =%s\n", ft_itoa_len(-2147483648), 
	ft_itoa(-2147483648));
	printf("num =%d | string =%s\n", ft_itoa_len(2147483647), ft_itoa(2147483647));
	printf("num =%d | string =%s\n", ft_itoa_len(-21474), ft_itoa(-21474));
	printf("num =%d | string =%s\n", ft_itoa_len(21474), ft_itoa(21474));
	return (0);
}*/
