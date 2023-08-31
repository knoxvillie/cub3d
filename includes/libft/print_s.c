/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:47:56 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/12/03 20:32:37 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_str_with_precision(t_var_print *var, char *res)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (var->precision + 1));
	while (i < var->precision)
		*(tmp + i++) = *(res++);
	*(tmp + i) = '\0';
	return (tmp);
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

int	print_s(t_var_print *var, char *str)
{
	char	*res;
	char	*tmp;
	int		count;

	count = 0;
	if (str == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(str);
	if (var->flagdot && var->precision < (int)ft_strlen(str))
	{
		tmp = ft_str_with_precision(var, res);
		free (res);
		res = tmp;
	}
	res = deal_with_minus(var, res);
	count = write(1, res, ft_strlen(res));
	free(res);
	return (count);
}
