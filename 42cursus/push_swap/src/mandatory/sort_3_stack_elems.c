/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_stack_elems.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:34:00 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/04 01:01:06 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_3_stack_elems(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && third > first)
		ft_sa(*stack, 1);
	else if (first > second && second > third && third < first)
	{
		ft_sa(*stack, 1);
		ft_rra(stack, 1);
	}
	else if (first > second && second < third && third < first)
		ft_ra(stack, 1);
	else if (first < second && second > third && third > first)
	{
		ft_sa(*stack, 1);
		ft_ra(stack, 1);
	}
	else if (first < second && second > third && third < first)
		ft_rra(stack, 1);
}
