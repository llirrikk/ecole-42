/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:42:42 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/31 16:34:59 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

typedef struct s_check_map
{
	unsigned int	exit_count;
	unsigned int	collectible_count;
	unsigned int	starting_position;
}	t_check_map;

static void	check_map_vars_init(t_check_map *check_map)
{
	check_map->exit_count = 0;
	check_map->collectible_count = 0;
	check_map->starting_position = 0;
}

static void	check_map_count_items(t_check_map *check_map, char map_cell)
{
	if (map_cell == 'E')
		check_map->exit_count++;
	else if (map_cell == 'C')
		check_map->collectible_count++;
	else if (map_cell == 'P')
		check_map->starting_position++;
}

static int	define_map_errors(int i, int j, t_map map)
{
	if (map.array[i][j] != '0' && map.array[i][j] != '1' \
		&& map.array[i][j] != 'C' && map.array[i][j] != 'E' \
		&& map.array[i][j] != 'P')
		return (ONLY_5_CHARACTERS_MAP_ERROR);
	if (i == 0 || j == 0 || i == map.height - 1 || j == map.width - 1)
		if (map.array[i][j] != '1')
			return (NOT_SURROUNDED_BY_WALLS_MAP_ERROR);
	return (0);
}

int	check_map(t_map map)
{
	int			i;
	int			j;
	t_check_map	check_map;

	check_map_vars_init(&check_map);
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			check_map_count_items(&check_map, map.array[i][j]);
			if (define_map_errors(i, j, map) != 0)
				return (define_map_errors(i, j, map));
			j++;
		}
		i++;
	}
	if (check_map.exit_count * check_map.collectible_count == 0)
		return (EXIT_COLLECTIBLE_STARTING_POSITION_MAP_ERROR);
	if (check_map.starting_position != 1)
		return (EXIT_COLLECTIBLE_STARTING_POSITION_MAP_ERROR);
	return (0);
}
