/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:07:03 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/19 15:16:18 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list_ptr;

	while (begin_list)
	{
		list_ptr = begin_list;
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			return (list_ptr);
		begin_list = begin_list->next;
	}
	return ((void *)0);
}
