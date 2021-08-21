/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:30:25 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/21 19:21:43 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

void	ft_list_push_back(t_numbers **begin_list, char *digit, char *text)
{
	t_numbers	*my_struct;

	my_struct->digit = digit;
	my_struct->text = text;
	my_struct->next = NULL;
	return (my_struct);
}
