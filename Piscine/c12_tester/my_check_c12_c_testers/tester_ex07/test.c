/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:15:02 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/18 18:22:59 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void ft_print_list(struct s_list *begin)
{
	while (begin)
	{
		printf("%s\n", begin->data);
		begin = begin->next;
	}
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


t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);

int main()
{
	t_list *list;
	list = ft_create_elem("Test 1");
	ft_list_push_back(&list, "Test 2");
	ft_list_push_back(&list, "Test 3");
	ft_list_push_back(&list, "Test 4");
	ft_list_push_back(&list, "Test 5");

	printf("%s\n", ft_list_at(list, 0)->data);
	printf("%s\n", ft_list_at(list, 1)->data);
	printf("%s\n", ft_list_at(list, 2)->data);
	printf("%s\n", ft_list_at(list, 3)->data);
	printf("%s\n", ft_list_at(list, 4)->data);
	printf("%s\n", (ft_list_at(list, 5) == NULL) ? "it's null" : "KO <--------");
	printf("%s\n", (ft_list_at(list, 6) == NULL) ? "it's null" : "KO <--------");
	printf("%s\n", (ft_list_at(list, 7) == NULL) ? "it's null" : "KO <--------");
}
