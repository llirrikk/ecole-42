/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:18:03 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/05 18:18:12 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_args_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (!(ft_atol(argv[i]) >= MIN_INT && ft_atol(argv[i]) <= MAX_INT))
			return (0);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
