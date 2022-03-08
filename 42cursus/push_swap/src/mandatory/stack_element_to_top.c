/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_element_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:30:45 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/04 01:01:03 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	move_element_to_top_of_stack(t_stack **stack, int index, \
										int a_or_b, t_all *all)
{
	if (index > find_stack_size(*stack) / 2)
	{
		while (index < find_stack_size(*stack))
		{
			if (a_or_b == 2)
				all->expected_moves.rrb++;
			else
				all->expected_moves.rra++;
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			if (a_or_b == 2)
				all->expected_moves.rb++;
			else
				all->expected_moves.ra++;
			index--;
		}
	}
}

int	find_point_to_raise_up(t_stack *stack, int element)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == element)
		{
			if (i > find_stack_size(stack) / 2)
				return (find_stack_size(stack) - i);
			return (i);
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}
