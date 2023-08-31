/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:22:13 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/27 18:05:48 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_var(t_var_print *var)
{
	var->isnumneg = 0;
	var->flagzero = 0;
	var->precision = 0;
	var->flagdot = 0;
	var->width = 0;
	var->flagplus = 0;
	var->flagminus = 0;
	var->flaghash = 0;
	var->flagspace = 0;
	var->specifier = 0;
}

int	ft_print_conversion(va_list *arg, t_var_print *var)
{
	if (var->specifier == 'c')
		return (print_c(var, va_arg(*arg, int)));
	else if (var->specifier == '%')
		return (print_per(var));
	else if (var->specifier == 'p')
		return (print_p(var, va_arg(*arg, unsigned long long)));
	else if (var->specifier == 's')
		return (print_s(var, va_arg(*arg, char *)));
	else if (var->specifier == 'u')
		return (print_u(var, va_arg(*arg, unsigned int)));
	else if (var->specifier == 'd' || var->specifier == 'i')
		return (print_d(var, va_arg(*arg, int)));
	else if (var->specifier == 'x' || var->specifier == 'X')
		return (print_x(var, va_arg(*arg, unsigned int)));
	return (0);
}

static void	read_format_flag(char const **format, t_var_print *var)
{
	while (!(ft_strchr(SPECIFIER, **format))
		&& !(**format >= '1' && **format <= '9') && **format != '.')
	{
		if (**format == '-')
			var->flagminus = 1;
		else if (**format == '+')
			var->flagplus = 1;
		else if (**format == ' ')
			var->flagspace = 1;
		else if (**format == '#')
			var->flaghash = 1;
		else if (**format == '0')
			var->flagzero = 1;
		(*format)++;
	}
}

int	read_format(char const **format, va_list *arg, t_var_print *var)
{
	int	count;

	read_format_flag(format, var);
	while (!(ft_strchr(SPECIFIER, **format)) && **format != '.')
	{
		if (**format >= '0' && **format <= '9')
			var->width = var->width * 10 + (**format - 48);
		(*format)++;
	}
	while (!(ft_strchr(SPECIFIER, **format))
		&& !(**format >= '0' && **format <= '9'))
	{
		if (**format == '.')
			var->flagdot = 1;
		(*format)++;
	}
	while (!(ft_strchr(SPECIFIER, **format)))
	{
		if (**format >= '0' && **format <= '9')
			var->precision = var->precision * 10 + (**format - 48);
		(*format)++;
	}
	var->specifier = **format;
	count = ft_print_conversion(arg, var);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	t_var_print	var;
	int			count;
	int			size;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			init_var(&var);
			format++;
			size = read_format(&format, &arg, &var);
			count += size;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	va_end(arg);
	return (count);
}
