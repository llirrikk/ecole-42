/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:21:33 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/19 13:30:28 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	print_data(void *data)
{
	printf("list.data = '%s'\n", data);
}

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

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;

	if (*begin_list)
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

int main(void)
{
	t_list *list;

	list = ft_create_elem("Test 1");
	ft_list_push_back(&list, "Test 2");
	ft_list_push_back(&list, "Test 3");
	ft_list_push_back(&list, "Test 4");
	ft_list_push_back(&list, "Test 5");

	ft_list_foreach(list, &print_data);
}
