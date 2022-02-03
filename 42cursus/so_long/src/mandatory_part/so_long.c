/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:39:30 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/30 22:30:43 by sserwyn          ###   ########.fr       */
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
		printf("Number of movements: %d\n", ++(game->moves));
	if (ate == 'C')
		(game->items_collected)++;
	if (ate == 'E' && game->map.items_to_collect == 0)
		user_won(game);
	create_frame(game, 0);
	return (0);
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
	init_imgs(&(game.mlx), &(game.map.img));
	create_frame(&game, 0);
	mlx_loop(game.mlx.ptr);
}
