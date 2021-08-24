/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:10 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/24 16:53:05 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // <----------------
#include <stdlib.h>

char	**read_console(char **first_line);
char	**read_file(char *file_name, char **first_line);
int		**map_to_cash(char **map, char *first_line);

int	main(int argc, char **argv)
{
	int		i;
	char	*first_line;
	char	**map;
	int		**cash;

	map = NULL;
	first_line = NULL;
	if (argc == 1)
		map = read_console(&first_line);
	else if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			map = read_file(argv[i], &first_line);
			i++;
		}
	}


	printf("IJFE");

	cash = map_to_cash(map, first_line);
	(void) cash;

	

	// for (int i = 0; i < 3; i++)
	// {
	// 	for (int j = 0; j < 3; j++)
	// 	{
	// 		printf("(%c)", map[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	// FREE
	// for (int i = 0; i < 3; i++)
	// {
	// 	free(map[i]);
	// }
	// free(map);
	// FREE
}
