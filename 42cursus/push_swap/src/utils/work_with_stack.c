/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:08:17 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/08 03:35:18 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		stack_len;

	tmp = stack;
	stack_len = 0;
	while (tmp)
	{
		stack_len++;
		tmp = tmp->next;
	}
	return (stack_len);
}

void	parse_to_stack(t_all *all)
{
	int		i;

	i = 1;
	while (i < all->argc)
	{
		ft_list_push_back(&(all->a), ft_atoi(all->argv[i]));
		i++;
	}
}

int	is_stack_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->value >= tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
