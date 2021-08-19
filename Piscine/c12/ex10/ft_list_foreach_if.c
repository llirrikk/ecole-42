/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:31:12 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/19 15:02:37 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(	t_list	*begin_list,
							void	(*f)(void *),
							void	*data_ref,
							int		(*cmp)()
						  )
{
	t_list	*list_ptr;

	while (begin_list)
	{
		list_ptr = begin_list;
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			(*f)(list_ptr->data);
		begin_list = begin_list->next;
	}
}
