/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:24:05 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/18 18:30:15 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void	ft_list_swap_elem(t_list **x, t_list **y)
{
	t_list	*temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	ft_list_reverse(t_list **begin_list)
{
	int	size;
	int	i;

	i = 0;
	size = ft_list_size(begin_list);
	while (i < size / 2)
	{
		*begin_list = *(begin_list + size - 1);
		i++;
	}
}
