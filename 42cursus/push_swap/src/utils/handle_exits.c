/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:29:18 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/05 18:29:09 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	lsts_clear_before_exit(t_all *all)
{
	ft_lstclear(&(all->a));
	ft_lstclear(&(all->b));
}

void	handled_exit(t_all *all)
{
	lsts_clear_before_exit(all);
	exit(0);
}

void	error_handled_exit(t_all *all)
{
	lsts_clear_before_exit(all);
	write(2, "Error\n", 6);
	exit(1);
}
