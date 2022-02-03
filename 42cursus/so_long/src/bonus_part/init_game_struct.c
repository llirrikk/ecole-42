/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:43:01 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/31 18:35:03 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_game_struct(t_game *game)
{
	game->moves = 0;
	game->items_collected = 0;
	game->is_exit_open = FALSE;
}
