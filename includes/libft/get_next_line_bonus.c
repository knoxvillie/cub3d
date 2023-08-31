/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:03:53 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/22 11:03:53 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(*(str + i)))
		return (NULL);
	while (*(str + i) && *(str + i) != '\n')
		i++;
	tmp = ft_calloc(sizeof(char), (i + 2));
	i = 0;
	while (*(str + i) && *(str + i) != '\n')
	{
		*(tmp + i) = *(str + i);
		i++;
	}
	*(tmp + i) = *(str + i);
	return (tmp);
}

char	*save_rest(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(str + i) && *(str + i) != '\n')
		i++;
	if (!(*(str + i)))
	{
		free (str);
		return (NULL);
	}
	tmp = ft_calloc(sizeof(char), (ft_strlen(str) - i));
	i++;
	while (*(str + i))
		*(tmp + (j++)) = *(str + (i++));
	free (str);
	return (tmp);
}

char	*ft_read_line(char *str, char *buffer, ssize_t len_read)
{
	char	*tmp;

	buffer[len_read] = '\0';
	if (str == NULL)
	{
		tmp = ft_strdup(buffer);
		free(str);
		return (tmp);
	}
	else
	{
		tmp = ft_strjoin(str, buffer);
		free(str);
		return (tmp);
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		len_read;
	static char	*str[FOPEN_MAX];
	char		*line;

	len_read = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (!(ft_strchr(buffer, '\n')) && len_read != 0)
	{
		len_read = read(fd, buffer, BUFFER_SIZE);
		if (len_read == -1)
		{
			free (buffer);
			free (str[fd]);
			str[fd] = NULL;
			return (NULL);
		}
		str[fd] = ft_read_line(str[fd], buffer, len_read);
	}
	free(buffer);
	line = get_line(str[fd]);
	str[fd] = save_rest(str[fd]);
	return (line);
}
/*int main()
{
	int fd,fd1,fd2;
	char	*str,*str1,*str2;
	int	i;

	fd = open("tests/foo.txt", O_RDONLY | O_CREAT);
	if (fd < 0) { perror("r1"); exit(1); }
	fd1 = open("tests/foo1.txt", O_RDONLY | O_CREAT);
	if (fd1 < 0) { perror("r1"); exit(1); }
	fd2 = open("tests/foo2.txt", O_RDONLY | O_CREAT);
	if (fd2 < 0) { perror("r1"); exit(1); }
	i = 0;
	while ((str = get_next_line(fd)))
	{
		printf("fd - %3d || LINE - %3d || lengh -
		%3d: %s",fd,i++,ft_strlen(str), str);
	}
	i = 0;
	while ((str1 = get_next_line(fd1)))
	{
		printf("fd - %3d || LINE - %3d || lengh -
		%3d: %s",fd1,i++,ft_strlen(str1), str1);
	}
	i = 0;
	while ((str2 = get_next_line(fd2)))
	{
		printf("fd - %3d || LINE - %3d || lengh -
		%3d: %s",fd2,i++,ft_strlen(str2), str2);
	}

	// while ((str2 = get_next_line(fd2)) &&
	(str1 = get_next_line(fd1)) && (str = get_next_line(fd)))
	// {
	// 	printf("fd - %3d || LINE - %3d || lengh -
	%3d: %s",fd,i++,ft_strlen(str), str);
	// 	printf("fd - %3d || LINE - %3d || lengh -
	%3d: %s",fd1,i++,ft_strlen(str1), str1);
	// 	printf("fd - %3d || LINE - %3d || lengh -
	%3d: %s",fd2,i++,ft_strlen(str2), str2);
	// }


	return (0);
}*/
