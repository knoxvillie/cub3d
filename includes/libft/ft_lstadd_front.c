/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:03:09 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:03:14 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = (*lst);
		(*lst) = new;
	}
}
/*#include<stdio.h>
int	main(void)
{
	t_list	*temp;
	t_list	*head;
	t_list	*new1;
	t_list	*new2;
	t_list	*newdata;
	int	*num0 = malloc(sizeof(int));
	int	*num1 = malloc(sizeof(int));
	int	*num2 = malloc(sizeof(int));
	int	*numdata = malloc(sizeof(int));
	*num0 = 1;
	*num1 = 10;
	*num2 = 11;
	*numdata  = 30;

	head = ft_lstnew(num0);
	new1 = ft_lstnew(num1);
	new2 = ft_lstnew(num2);
	newdata = ft_lstnew(numdata);
	head->next = new1;
	new1->next = new2;
	temp = head;
	//print all elements of the list
	while(temp != NULL)
	{
		printf("%d ", *(int *)(temp->content));
		temp = temp->next;
	}
	printf("\n");
	// add new element in the begining of the list and update temp
	ft_lstadd_front(&head, newdata);
	temp = head;
	//print all the elements of the new list
	while(temp != NULL)
	{
		printf("%d ", *(int *)(temp->content));
		temp = temp->next;
	}
	printf("\n");
	return (0);
}*/
