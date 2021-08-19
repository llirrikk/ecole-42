/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:02:42 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/19 17:59:31 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// void	free_fct(void *data)
// {
// 	free(data);
// }

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*current;

	while (begin_list->next)
	{
		current = begin_list;
		begin_list = begin_list->next;
		free_fct(current->data);
		free(current);
		current = (void *)0;
	}
	free_fct(begin_list->data);
	free(begin_list);
	begin_list = (void *)0;
}
