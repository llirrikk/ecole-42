/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back_alloc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:38:34 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/21 18:45:45 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

t_numbers	*ft_create_elem_alloc(int digit_size, int text_size);

void	ft_list_push_back_alloc(t_numbers **begin_list, int digit_size, int text_size)
{
	t_numbers	*list;

	if (*begin_list)
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = ft_create_elem_alloc(digit_size, text_size);
	}
	else
		*begin_list = ft_create_elem_alloc(digit_size, text_size);
}
