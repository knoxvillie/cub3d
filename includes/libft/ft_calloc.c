/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:44:55 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 11:46:32 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = (void *)malloc(nmemb * size);
	if (p == NULL)
		return (p);
	ft_bzero(p, nmemb * size);
	return (p);
}
/*#include <stdio.h>
int	main(void)
{
	char	*p,*p1;
	int	n = 100; //test with n = 1000000000000 to overflow
	int	i = 0;
	p = (char *)ft_calloc(n, sizeof(char));
	p1 = (char *)calloc(n, sizeof(char));
	if (p == NULL)
		printf("erro em p\n");
	else
		printf("endereco de p : %p\n", p);
	if (p1 == NULL)
		printf("erro em p1\n");
	else
		printf("endereco de p1 : %p\n", p1);
	while (i<n)
	{
		printf("%d ",p[i]);
		// printf("%p\n", &p[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i<n)
	{
		printf("%d ",p1[i]);
		// printf("%p\n", &p1[i]);
		i++;
	}
	printf("\n");
	free(p);
	free(p1);
	return (0);
}*/
