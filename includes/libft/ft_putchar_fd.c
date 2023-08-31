/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:28:38 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 22:09:53 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}
	printf("fd = %d\n", fd);
	ft_putchar_fd('f', fd);
	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return (1);
	}
	return (0);
}*/
