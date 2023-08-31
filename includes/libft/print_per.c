/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:25:22 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/12/03 08:09:18 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_per(t_var_print *var)
{
	if (!(var->flagminus) && !(var->flagdot)
		&& !(var->flaghash) && !(var->flagplus)
		&& !(var->flagspace) && !(var->flagzero))
		return (write(1, "%", 1));
	return (0);
}
