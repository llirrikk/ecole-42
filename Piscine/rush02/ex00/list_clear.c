/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:37:40 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/22 20:52:01 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

t_numbers	*remove_all_list(t_numbers *head)
{
	t_numbers	*p;

	while (head != NULL)
	{
		p = head;
		head = head->next;
		free(p->text);
		free(p->digit);
		free(p);
	}
	return (NULL);
}
