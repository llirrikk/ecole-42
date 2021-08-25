/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleans.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:07:52 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/25 15:10:43 by sserwyn          ###   ########.fr       */
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
