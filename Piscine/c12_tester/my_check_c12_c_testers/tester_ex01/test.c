/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:06:33 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/18 15:41:16 by sserwyn          ###   ########.fr       */
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

t_list	*ft_create_elem(void *data);

void	ft_list_push_front(t_list **begin_list, void *data);

int	main(void)
{
	t_list	*list;

	list = ft_create_elem("Test 1");
	ft_list_push_front(&list, "Test 2");
	ft_list_push_front(&list, "Test 3");
	ft_list_push_front(&list, "Test 4");
	ft_print_list(list);

	t_list	*empty_list;

	empty_list = NULL;
	ft_list_push_front(&empty_list, "Test");
	ft_print_list(empty_list);
}
