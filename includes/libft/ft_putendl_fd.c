/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:03:37 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 13:03:37 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	char	*s = "ola";

	fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
	// fd = open("test.txt", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}
	printf("fd = %d\n", fd);
	ft_putendl_fd(s, fd);
	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return (1);
	}
	return (0);
}*/
