/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:38:34 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/21 19:20:44 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

t_numbers	*ft_create_elem(int digit_size, int text_size);

void	ft_list_push_back(t_numbers **begin_list, char *digit, char *text)
{
	t_numbers	*list;

	if (*begin_list)
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(digit, text);
	}
	else
		*begin_list = ft_create_elem(digit, text);
}
