/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:23:41 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/30 16:34:49 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	paste_img_to_window(int i, int j, t_map *map, t_mlx mlx)
{
	if (map->array[i][j] == '0')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.empty, \
								CELL_SIZE * j, CELL_SIZE * i);
	else if (map->array[i][j] == '1')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.wall, \
								CELL_SIZE * j, CELL_SIZE * i);
	else if (map->array[i][j] == 'C')
	{
		(map->items_to_collect)++;
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.collectable_item, \
								CELL_SIZE * j, CELL_SIZE * i);
	}
	else if (map->array[i][j] == 'E')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.exit, \
								CELL_SIZE * j, CELL_SIZE * i);
	else if (map->array[i][j] == 'P')
	{
		map->player_position.x = j;
		map->player_position.y = i;
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.player, \
								CELL_SIZE * j, CELL_SIZE * i);
	}
}

void	create_frame(t_game *game, int is_move)
{
	int		i;
	int		j;

	(void) is_move;
	game->map.items_to_collect = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			paste_img_to_window(i, j, &(game->map), game->mlx);
			j++;
		}
		i++;
	}
}
