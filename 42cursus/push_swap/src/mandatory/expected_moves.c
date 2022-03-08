/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expected_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:35:54 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/05 18:00:19 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	init_expected_moves(t_all *all)
{
	all->expected_moves.ra = 0;
	all->expected_moves.rb = 0;
	all->expected_moves.rra = 0;
	all->expected_moves.rrb = 0;
}

static void	make_moves_via_expected_moves_2(t_all *all)
{
	while (all->expected_moves.rra > 0 && all->expected_moves.rrb > 0)
	{
		ft_rrr(&(all->a), &(all->b), 1);
		all->expected_moves.rra--;
		all->expected_moves.rrb--;
	}
	while (all->expected_moves.rra > 0)
	{
		ft_rra(&(all->a), 1);
		all->expected_moves.rra--;
	}
	while (all->expected_moves.rrb > 0)
	{
		ft_rrb(&(all->b), 1);
		all->expected_moves.rrb--;
	}
}

void	make_moves_via_expected_moves(t_all *all)
{
	while (all->expected_moves.ra > 0 && all->expected_moves.rb > 0)
	{
		ft_rr(&(all->a), &(all->b), 1);
		all->expected_moves.ra--;
		all->expected_moves.rb--;
	}
	while (all->expected_moves.ra > 0)
	{
		ft_ra(&(all->a), 1);
		all->expected_moves.ra--;
	}
	while (all->expected_moves.rb > 0)
	{
		ft_rb(&(all->b), 1);
		all->expected_moves.rb--;
	}
	make_moves_via_expected_moves_2(all);
}
