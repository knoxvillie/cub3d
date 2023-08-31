/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:28:54 by marvin            #+#    #+#             */
/*   Updated: 2022/11/08 08:28:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL && f != NULL)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
/*static void	ft_delete(void	*data)
{
	if (data != NULL)
		free (data);
}
static void	ft_addnode(int	*data)
{
	if (data != NULL)
		*data = *data + 10;
}
#include<stdio.h>
int	main(void)
{
	t_list	*temp;
	t_list	*head;
	t_list	*new1;
	t_list	*new2;
	t_list	*new3;
	t_list	*new5;
	t_list	*newdel;
	t_list	*newdata;
	int	*num0 = malloc(sizeof(int));
	int	*num1 = malloc(sizeof(int));
	int	*num2 = malloc(sizeof(int));
	int	*num3 = malloc(sizeof(int));
	int	*num4 = malloc(sizeof(int));
	int	*num5 = malloc(sizeof(int));
	int	*num6 = malloc(sizeof(int));
	int	*numdata = malloc(sizeof(int));
	int	*numdel = malloc(sizeof(int));
	*num0 = 1;
	*num1 = 10;
	*num2 = 11;
	*num3 = 14;
	*num4 = 155;
	*num5 = 166;
	*num6 = 200;
	*numdata  = 30;
	*numdel = 16;

	new3 = ft_lstnew(num6);
	head = ft_lstnew(num0);
	new1 = ft_lstnew(num1);
	new2 = ft_lstnew(num2);
	new5 = ft_lstnew(num5);
	newdel = ft_lstnew(numdel);
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

	// add new element in the begining of the list and update temp
	ft_lstadd_front(&head, newdata);
	ft_lstadd_front(&head, ft_lstnew(num3));
	ft_lstadd_back(&head, ft_lstnew(num4));
	ft_lstadd_back(&head, new5);
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

	// free a content's node from a list
	printf("the content to be freed is:%d\n", *(int *)(newdel->content));
	ft_lstdelone(newdel, &ft_delete);

	// clear - Deletes and frees all the list
	// ft_lstclear(&head, &ft_delete);
	// printf("the head is:%p. It should be NULL.\n", head);

	// lstiter - Iterates the list ’lst’ and applies the function
	//"ft_addnode" on the content of each node
	ft_lstiter(head, (void (*)(void*))&ft_addnode);
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
