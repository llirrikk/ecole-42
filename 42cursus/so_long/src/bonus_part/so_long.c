/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:39:30 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/31 18:33:37 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	action(int keycode, t_game *game)
{
	char	ate;

	if (keycode == KEY_ESC)
		user_close(game);
	if (!is_move_keys(keycode))
		return (0);
	if (game->map.items_to_collect == 0)
		game->is_exit_open = TRUE;
	ate = move_player(&(game->map), keycode, game->is_exit_open);
	if (ate != '1' && !(game->is_exit_open == FALSE && ate == 'E'))
		++(game->moves);
	if (ate == 'C')
		(game->items_collected)++;
	if (ate == 'E' && game->map.items_to_collect == 0)
		user_won(game);
	if (ate == 'S')
		user_died(game);
	create_frame(game, TRUE);
	return (0);
}

int	update(t_game *game)
{
	create_frame(game, FALSE);
	return (0);
}

void	put_enemies_to_map(t_map *map)
{
	int	i;
	int	j;

	srand(time(NULL));
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j] == '0' && rand() % (100 / ENEMY_RAND_CF) == 0)
				map->array[i][j] = 'S';
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	handle_args_error(argc);
	init_game_struct(&game);
	handle_map_parse_errors(parse_ber_file(&game.map, argv[1]));
	handle_map_check_errors(check_map(game.map));
	game.mlx.ptr = mlx_init();
	game.mlx.win = mlx_new_window(game.mlx.ptr, game.map.width * CELL_SIZE, \
									game.map.height * CELL_SIZE, WINDOW_TITLE);
	mlx_hook(game.mlx.win, 17, 0, user_close, (void *)&game);
	mlx_hook(game.mlx.win, 2, 1L << 0, action, (void *)&game);
	mlx_loop_hook(game.mlx.ptr, update, &game);
	init_imgs(&(game.mlx), &(game.map.img));
	put_enemies_to_map(&(game.map));
	create_frame(&game, TRUE);
	mlx_loop(game.mlx.ptr);
}
