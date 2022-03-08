/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:30:25 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/04 01:01:29 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*ft_create_elem(int data)
{
	t_stack	*my_struct;

	my_struct = (t_stack *)malloc(sizeof(t_stack));
	if (my_struct == NULL)
		return (NULL);
	my_struct->value = data;
	my_struct->next = NULL;
	return (my_struct);
}
