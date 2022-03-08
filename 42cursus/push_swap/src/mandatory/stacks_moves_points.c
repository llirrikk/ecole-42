/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_moves_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:32:50 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/05 18:00:55 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	find_min_point_and_index(t_all *all, \
									int *tmp_min_point, int *tmp_index_in_b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = all->b;
	*tmp_min_point = tmp->move_point;
	*tmp_index_in_b = 0;
	while (tmp)
	{
		if (tmp->move_point < *tmp_min_point)
		{
			*tmp_min_point = tmp->move_point;
			*tmp_index_in_b = i;
		}
		i++;
		tmp = tmp->next;
	}
}

void	move_to_a_min_point(t_all *all)
{
	t_stack	*tmp;
	int		tmp_min_point;
	int		tmp_index_in_b;

	find_min_point_and_index(all, &tmp_min_point, &tmp_index_in_b);
	init_expected_moves(all);
	tmp = all->b;
	while (tmp)
	{
		if (tmp->move_point == tmp_min_point)
		{
			move_element_to_top_of_stack(&(all->b), tmp_index_in_b, 2, all);
			prepare_a_to_put_in(&(all->a), tmp->value, all);
			make_moves_via_expected_moves(all);
			ft_pa(&(all->a), &(all->b), 1);
			return ;
		}
		tmp = tmp->next;
	}
}

void	find_b_to_a_points(t_all *all)
{
	t_stack	*tmp;

	tmp = all->b;
	while (tmp)
	{
		tmp->move_point = find_point_to_raise_up(all->b, tmp->value) + \
				find_point_to_raise_up(all->a, find_value_from_index(all->a, \
				find_right_index_from_top_in_a(all->a, tmp->value)));
		tmp = tmp->next;
	}
}
