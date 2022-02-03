/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:21:38 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/30 16:09:18 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	move_if_way_clear(t_map *map, t_position old, \
								t_position new, int is_exit_open)
{
	char	ate;

	ate = '1';
	if (map->array[new.y][new.x] != '1')
	{
		ate = map->array[new.y][new.x];
		map->array[new.y][new.x] = 'P';
		map->array[old.y][old.x] = '0';
	}
	if (is_exit_open == FALSE && ate == 'E')
	{
		map->array[old.y][old.x] = 'P';
		map->array[new.y][new.x] = 'E';
	}
	return (ate);
}

int	is_move_keys(int keycode)
{
	return (keycode == KEY_W || keycode == KEY_UP || \
				keycode == KEY_A || keycode == KEY_LEFT || \
				keycode == KEY_S || keycode == KEY_DOWN || \
				keycode == KEY_D || keycode == KEY_RIGHT);
}

static void	handle_move_keys(int keycode, t_position *old_pos, \
								t_position *new_pos)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		new_pos->x = old_pos->x;
		new_pos->y = old_pos->y - 1;
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		new_pos->x = old_pos->x - 1;
		new_pos->y = old_pos->y;
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		new_pos->x = old_pos->x;
		new_pos->y = old_pos->y + 1;
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		new_pos->x = old_pos->x + 1;
		new_pos->y = old_pos->y;
	}
}

char	move_player(t_map *map, int keycode, int is_exit_open)
{
	t_position	old_pos;
	t_position	new_pos;

	old_pos.x = map->player_position.x;
	old_pos.y = map->player_position.y;
	handle_move_keys(keycode, &old_pos, &new_pos);
	return (move_if_way_clear(map, old_pos, new_pos, is_exit_open));
}
