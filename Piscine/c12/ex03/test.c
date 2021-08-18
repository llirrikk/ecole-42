/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:25:34 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/18 15:37:07 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*my_struct;

	my_struct = (t_list *)malloc(sizeof(t_list));
	if (my_struct == NULL)
		return (NULL);
	my_struct->data = data;
	my_struct->next = NULL;
	return (my_struct);
}

/*
list = ft_create_elem(data);
if (list)
{
	list->next = *begin_list;
	*begin_list = list;
}
*/
void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list;

	if (*begin_list)
	{
		list = ft_create_elem(data);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = ft_create_elem(data);
}

t_list	*ft_list_last(t_list *begin_list);

int main(void)
{
	t_list *list;

	list = ft_create_elem("Test 1");
	ft_list_push_front(&list, "Test 2");
	ft_list_push_front(&list, "Test 3");
	ft_list_push_front(&list, "Test 4");
	ft_list_push_front(&list, "Test 5");
	printf("res1 = %s\n", ft_list_last(list)->data);

	t_list *empty_list;
	empty_list = NULL;
	printf("res2 = %s\n", (ft_list_last(empty_list) == NULL) ? "it's null" : "KO <---------");
}
