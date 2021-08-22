/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:17:42 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/22 16:33:02 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // <------------------------------------------------

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

int			ft_strlen(char *str);
t_numbers	*ft_list_find_digit(t_numbers *begin_list, char *data_ref);

void number_finder(t_numbers *dict, char *digits)
{
	int		i;
	char	triple[4];

	i = 0;
	while (i < (ft_strlen(digits) % 3))
	{
		triple[i] = digits[i];
		i++;
	}
	triple[i] = '\0';
	printf("> %s\n", triple);
	(void) dict;
	
}
