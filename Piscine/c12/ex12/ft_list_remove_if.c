/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:19:27 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/19 18:00:06 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// void	free_fct(void *data)
// {
// 	free(data);
// }

void	ft_list_remove_if(	t_list	**begin_list,
							void	*data_ref,
							int		(*cmp)(),
							void	(*free_fct)(void *)
						 )
{
	t_list	*list_ptr;

	while ((*begin_list)->next)
	{
		list_ptr = *begin_list;
		*begin_list = (*begin_list)->next;
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			(*free_fct)(list_ptr->data);
			free(list_ptr);
		}
	}
	if ((*cmp)(list_ptr->data, data_ref) == 0)
	{
		(*free_fct)((*begin_list)->data);
		free(begin_list);
	}
}
