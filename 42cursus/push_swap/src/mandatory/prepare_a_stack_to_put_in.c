/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a_stack_to_put_in.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:29:34 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/04 01:01:08 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_right_index_from_top_in_a(t_stack *a, int value_in_b)
{
	t_stack	*tmp;
	int		place_from_top;

	place_from_top = 0;
	tmp = a;
	while (tmp->next)
	{
		place_from_top++;
		if (value_in_b > tmp->value && value_in_b < tmp->next->value)
			return (place_from_top);
		tmp = tmp->next;
	}
	return (0);
}

void	prepare_a_to_put_in(t_stack **a, int element_to_put, t_all *all)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp->next)
	{
		if (element_to_put > tmp->value && element_to_put < tmp->next->value)
		{
			move_element_to_top_of_stack(a, i + 1, 1, all);
			return ;
		}
		i++;
		tmp = tmp->next;
	}	
}
