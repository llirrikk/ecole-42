/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:51:07 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/31 18:34:45 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_EXIT 17
# define KEY_ESC 65307

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define WINDOW_TITLE "so_long"
# define CELL_SIZE 72
# define ENEMY_RAND_CF 10

# define TRUE 1
# define FALSE 0
# define MALLOC_ERROR 999
# define NOT_SURROUNDED_BY_WALLS_MAP_ERROR 1000
# define EXIT_COLLECTIBLE_STARTING_POSITION_MAP_ERROR 1001
# define RECTANGULAR_MAP_ERROR 1002
# define ONLY_5_CHARACTERS_MAP_ERROR 1003

# define RED_PRINTF_MESSAGE "\033[31m"
# define YELLOW_PRINTF_MESSAGE "\033[33m"
# define GREEN_PRINTF_MESSAGE "\033[32m"
# define RESET_PRINTF_MESSAGE "\033[0m"

# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>

typedef struct s_enemy_img
{
	void	*enemy_right;
	void	*enemy_left;
}	t_enemy_img;

typedef struct s_img
{
	void				*empty;
	void				*wall;
	void				*collectable_item;
	void				*exit;
	void				*player;
	struct s_enemy_img	enemy;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_position
{
	unsigned int	x;
	unsigned int	y;
}	t_position;

typedef struct s_map
{
	struct s_mlx		mlx;
	struct s_img		img;
	char				**array;
	int					width;
	int					height;
	unsigned int		items_to_collect;
	struct s_position	player_position;
}	t_map;

typedef struct s_game
{
	struct s_mlx	mlx;
	struct s_map	map;
	unsigned int	moves;
	unsigned int	items_collected;
	int				is_exit_open;
}	t_game;

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_realloc(char *old, char ch);
char	*ft_itoa(int n);

int		ft_strlen_without_last_nl(const char *str);

void	init_imgs(t_mlx *mlx, t_img *img);
int		parse_ber_file(t_map *map, char *ber_file);
int		check_map(t_map map);
void	handle_args_error(int argc);
void	handle_map_check_errors(int errno);
void	handle_map_parse_errors(int errno);
int		is_move_keys(int keycode);
char	move_player(t_map *map, int keycode, int is_exit_open);
void	create_frame(t_game *game, int is_move);
void	init_game_struct(t_game *game);
int		user_won(t_game *game);
int		user_died(t_game *game);
int		user_close(t_game *game);

#endif
