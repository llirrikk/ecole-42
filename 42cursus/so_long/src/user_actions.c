/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:24:33 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/30 22:27:11 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->array[i]);
		i++;
	}
	free(map->array);
}

int	user_won(t_game *game)
{
	free_map(&(game->map));
	printf(GREEN_PRINTF_MESSAGE "YOU WIN!\n" RESET_PRINTF_MESSAGE);
	exit(0);
}

int	user_died(t_game *game)
{
	free_map(&(game->map));
	printf(YELLOW_PRINTF_MESSAGE "YOU DIED!\n" RESET_PRINTF_MESSAGE);
	exit(0);
}

int	user_close(t_game *game)
{
	free_map(&(game->map));
	exit(0);
}
