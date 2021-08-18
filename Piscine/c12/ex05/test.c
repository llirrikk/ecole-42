/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:09:14 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/18 17:01:05 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void ft_print_list(struct s_list *begin)
{
	while (begin)
	{
		printf("%s\n", begin->data);
		begin = begin->next;
	}
}

t_list	*ft_list_push_strs(int size, char **strs);

int main(void)
{
	t_list *list1;
	char *strs1[] = {"Hello", "World", "it", "test"};
	list1 = ft_list_push_strs(4, strs1);
	ft_print_list(list1);

	t_list *list2;
	char *strs2[] = {};
	list2 = ft_list_push_strs(0, strs2);
	ft_print_list(list2);

	t_list *list3;
	char *strs3[] = {"wwegweggwe"};
	list3 = ft_list_push_strs(1, strs3);
	ft_print_list(list3);

	t_list *list4;
	char *strs4[] = {"23895", "fwef", "F23", "2355"};
	list4 = ft_list_push_strs(2, strs4);
	ft_print_list(list4);
}
