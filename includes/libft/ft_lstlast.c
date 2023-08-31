/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:07:20 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/07 12:09:12 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
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
	int	*num3 = malloc(sizeof(int));
	int	*numdata = malloc(sizeof(int));
	*num0 = 1;
	*num1 = 10;
	*num2 = 11;
	*num3 = 14;
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
	//print the size of the list
	printf("length of the list is:%d\n", ft_lstsize(head));

	// add new element in the begining
	// of the list and update temp
	ft_lstadd_front(&head, newdata);
	ft_lstadd_front(&head, ft_lstnew(num3));
	temp = head;

	//print all the elements of the new list
	while(temp != NULL)
	{
		printf("%d ", *(int *)(temp->content));
		temp = temp->next;
	}
	printf("\n");

	//print the size of the list
	printf("length of the list is:%d\n", ft_lstsize(head));

	// print the data from the last element of the list
	printf("the data from the last element is:%d \n",
 *(int *)(ft_lstlast(head)->content));
	return (0);
}*/
