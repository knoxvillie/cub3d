/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:00:21 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 13:00:21 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*sub;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if ((size_t)start >= size)
		return (ft_strdup(""));
	if (size - 1 - start < len)
		len = size - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (s + start), len + 1);
	return (sub);
}
/*#include <stdio.h>
int	main(void)
{
    char const str1[] = "FabioValli";
	char	*sub;
    size_t len = 1;
	unsigned int start = 5;
	sub = ft_substr(str1, start, len);
    printf("%s and size of the string is : %zu \n", sub, ft_strlen(sub));

    return(0);
}*/
