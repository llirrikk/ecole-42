/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:21:54 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/19 18:02:22 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i))
	{
		if (*(s1 + i) == '\0')
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
}

void	free_fct(void *data)
{
	free(data);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

int main(void)
{
	t_list *list;

	list = ft_create_elem("Test 1");
	ft_list_push_back(&list, "Test 2");
	ft_list_push_back(&list, "Test 3");
	ft_list_push_back(&list, "Test 4");
	ft_list_push_back(&list, "Test 5");
	ft_list_push_back(&list, "Test 5");
	ft_list_push_back(&list, "Test 6");
	ft_list_push_back(&list, "Test 6");
	ft_list_push_back(&list, "Test 7");
	ft_list_push_back(&list, "Test 6");
	ft_list_push_back(&list, "Test 1");

	ft_list_remove_if(&list, "Test 1", &ft_strcmp, &free_fct);

	ft_print_list(list);




}
