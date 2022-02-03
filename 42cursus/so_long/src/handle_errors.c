/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:14:28 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/30 16:09:00 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_map_check_errors(int errno)
{
	if (errno == NOT_SURROUNDED_BY_WALLS_MAP_ERROR)
	{
		printf(RED_PRINTF_MESSAGE \
				"Error\nNOT_SURROUNDED_BY_WALLS_MAP_ERROR\n" \
				RESET_PRINTF_MESSAGE);
		exit(1);
	}
	else if (errno == EXIT_COLLECTIBLE_STARTING_POSITION_MAP_ERROR)
	{
		printf(RED_PRINTF_MESSAGE \
				"Error\nEXIT_COLLECTIBLE_STARTING_POSITION_MAP_ERROR\n" \
				RESET_PRINTF_MESSAGE);
		exit(1);
	}
	else if (errno == ONLY_5_CHARACTERS_MAP_ERROR)
	{
		printf(RED_PRINTF_MESSAGE \
				"Error\nONLY_5_CHARACTERS_MAP_ERROR\n" \
				RESET_PRINTF_MESSAGE);
		exit(1);
	}
}

void	handle_map_parse_errors(int errno)
{
	if (errno == RECTANGULAR_MAP_ERROR)
	{
		printf(RED_PRINTF_MESSAGE \
				"Error\nRECTANGULAR_MAP_ERROR\n" \
				RESET_PRINTF_MESSAGE);
		exit(1);
	}
	else if (errno == MALLOC_ERROR)
	{
		printf(RED_PRINTF_MESSAGE \
				"Error\nMALLOC_ERROR\n" \
				RESET_PRINTF_MESSAGE);
		exit(1);
	}
}

void	handle_args_error(int argc)
{
	if (argc != 2)
	{
		printf(YELLOW_PRINTF_MESSAGE \
				"Error\nInvalid argument number\n" \
				RESET_PRINTF_MESSAGE);
		exit(1);
	}
}
