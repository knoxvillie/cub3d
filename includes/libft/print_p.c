/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:51:03 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/12/03 20:24:13 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoa_hex_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*ft_itoa_hex(unsigned long long n)
{
	int					len;
	unsigned long long	num;
	char				*nb;

	num = n;
	len = ft_itoa_hex_len(num);
	if (n == 0)
		len = 1;
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (0);
	nb[len] = '\0';
	if (num == 0)
		nb[0] = '0';
	while (num > 0)
	{
		nb[len - 1] = "0123456789abcdef"[num % 16];
		num = num / 16;
		len --;
	}
	return (nb);
}

static char	*deal_with_minus(t_var_print *var, char *res)
{
	char	*tmp;

	if (var->flagminus)
	{
		tmp = ft_right_pad_space(var, res);
		free (res);
		res = tmp;
	}
	else
	{
		tmp = ft_left_pad_space(var, res);
		free (res);
		res = tmp;
	}
	return (res);
}

int	print_p(t_var_print *var, unsigned long long hex)
{
	char	*num;
	char	*res;
	int		count;

	count = 0;
	if (hex == 0)
		res = ft_strdup("(nil)");
	else
	{
		num = ft_itoa_hex(hex);
		res = ft_strjoin("0x", num);
		free(num);
	}
	res = deal_with_minus(var, res);
	count = write(1, res, ft_strlen(res));
	free(res);
	return (count);
}
