/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:29:06 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:29:06 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-', fd);
		}
		if (n < 10)
			ft_putchar_fd(n + 48, fd);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
/*#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	int	num = 100;
	int	num1 = -999;
	int	num2 = 2147483647;
	int	num3 = -2147483648;

	fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
	// fd = open("test.txt", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}
	printf("fd = %d\n", fd);
	ft_putnbr_fd(num, fd);
	ft_putnbr_fd(num1, fd);
	ft_putnbr_fd(num2, fd);
	ft_putnbr_fd(num3, fd);
	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return (1);
	}
	return (0);
}*/
