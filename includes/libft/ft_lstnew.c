/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:10:07 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:10:24 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*#include<stdio.h>
int	main(void)
{
	t_list	*new;
	int	*numnew;

	numnew = malloc(sizeof(int));
	*numnew = 10;
	new = ft_lstnew(numnew);
	printf("content is :%d\n", *(int *)(new->content));
	printf("next is :%p\n", new->next);
	free(new->content);
	// printf("content is :%d", ((int *)(new->content))[0]);
	return (0);
}*/
