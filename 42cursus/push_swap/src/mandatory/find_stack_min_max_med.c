/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_min_max_med.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:09:52 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/05 21:16:27 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	bubble_array_sort(int *sorted_array, int count_values)
{
	int	i;
	int	j;

	i = 0;
	while (i < count_values - 1)
	{
		j = i + 1;
		while (j < count_values - 2)
		{
			if (sorted_array[i] > sorted_array[j])
				ft_swap(&sorted_array[i], &sorted_array[j]);
			j++;
		}
		i++;
	}
}

static int	find_stack_median(t_stack *stack, int count_values)
{
	t_stack	*tmp;
	int		*sorted_array;
	int		i;
	int		median;

	sorted_array = (int *)malloc(sizeof(int) * (count_values - 1));
	tmp = stack;
	i = 0;
	while (tmp)
	{
		sorted_array[i++] = tmp->value;
		tmp = tmp->next;
	}
	bubble_array_sort(sorted_array, count_values);
	median = sorted_array[(count_values - 2) / 2];
	free(sorted_array);
	return (median);
}

void	find_min_max_med(t_all *all)
{
	t_stack	*tmp;

	all->min = MAX_INT;
	all->max = MIN_INT;
	tmp = all->a;
	while (tmp)
	{
		if (tmp->value < all->min)
			all->min = tmp->value;
		if (tmp->value > all->max)
			all->max = tmp->value;
		tmp = tmp->next;
	}
	all->med = find_stack_median(all->a, all->argc);
}

void	push_all_to_b_except_min_max_med(t_all *all)
{
	if (find_stack_size(all->b) == 0)
		find_min_max_med(all);
	if (find_stack_size(all->a) <= 3)
		return ;
	if (all->a->value == all->min || all->a->value == all->max || \
		all->a->value == all->med)
		ft_ra(&(all->a), 1);
	else if (all->a->value > all->med)
	{
		ft_pb(&(all->a), &(all->b), 1);
		ft_rb(&(all->b), 1);
	}
	else
		ft_pb(&(all->a), &(all->b), 1);
	push_all_to_b_except_min_max_med(all);
}
