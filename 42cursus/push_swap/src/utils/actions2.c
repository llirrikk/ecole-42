/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:16:00 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/05 15:25:07 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_rrr(t_stack **a, t_stack **b, int is_print)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (is_print)
		write(1, "rrr\n", 4);
}

void	ft_sa(t_stack *a, int is_print)
{
	int		buff;

	if (a == NULL || a->next == NULL)
		return ;
	buff = a->value;
	a->value = a->next->value;
	a->next->value = buff;
	if (is_print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, int is_print)
{
	int		buff;

	if (b == NULL || b->next == NULL)
		return ;
	buff = b->value;
	b->value = b->next->value;
	b->next->value = buff;
	if (is_print)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b, int is_print)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	if (is_print)
		write(1, "ss\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b, int is_print)
{
	t_stack	*buff;

	if (b == NULL)
		return ;
	buff = *b;
	*b = (*b)->next;
	buff->next = *a;
	*a = buff;
	if (is_print)
		write(1, "pa\n", 3);
}
