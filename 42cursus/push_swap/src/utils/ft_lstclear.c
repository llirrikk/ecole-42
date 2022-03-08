/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:06:53 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/04 01:01:16 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*old;

	while (*lst)
	{
		old = *lst;
		*lst = old->next;
		free(old);
	}
	*lst = NULL;
}
