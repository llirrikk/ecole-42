/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:16:33 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/05 15:21:11 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_pb(t_stack **a, t_stack **b, int is_print)
{
	t_stack	*buff;

	if (a == NULL)
		return ;
	buff = *a;
	*a = (*a)->next;
	buff->next = *b;
	*b = buff;
	if (is_print)
		write(1, "pb\n", 3);
}
