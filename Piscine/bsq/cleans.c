/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleans.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:07:52 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/25 16:08:39 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	number_1st_line(char *line);

void	free_map(char **map, char *first_line)
{
	int	i;

	i = 0;
	while (i < number_1st_line(first_line))
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_cash(int **cash, int hight)
{
	int	i;

	i = 0;
	while (i < hight)
	{
		free(cash[i]);
		i++;
	}
	free(cash);
}
