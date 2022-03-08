/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index2value_value2index.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:35:58 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/04 01:01:01 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_index_from_value(t_stack *stack, int value)
{
	t_stack	*tmp;
	int		index;

	index = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (0);
}

int	find_value_from_index(t_stack *stack, int index)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (i == index)
			return (tmp->value);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
