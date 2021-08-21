/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem_alloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:30:25 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/21 18:46:02 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

t_numbers	*ft_create_elem_alloc(int digit_size, int text_size)
{
	t_numbers	*my_struct;

	my_struct = (t_numbers *)malloc(sizeof(t_numbers));
	if (my_struct == NULL)
		return (NULL);

	my_struct->digit = (char *)malloc(sizeof(char) * digit_size);
	my_struct->text = (char *)malloc(sizeof(char) * text_size);
	my_struct->next = NULL;
	return (my_struct);
}
