/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:36:05 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:36:05 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	begin;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	begin = 0;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		++begin;
	while (s1[end] && ft_strchr(set, s1[end]))
		--end;
	res = ft_substr(s1, begin, end - begin + 1);
	return (res);
}
/*#include <stdio.h>
int	main(void)
{
	printf("Original string :%s\nSet of char:%s\nTrimmed string:%s\n",
	"\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n
	\t\t\t\t  ", "Hello \t  Please\n Trim me !", ft_strtrim("\t
	 \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n
	 \t\t\t\t  ", "Hello \t  Please\n Trim me !"));
}*/
