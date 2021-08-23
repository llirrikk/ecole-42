/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:10 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/23 20:05:22 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // <----------------
#include <stdlib.h>

char	**read_console(void);
char	**read_file(char *file_name);

int	main(int argc, char **argv)
{
	int		i;
	char	**map;

	if (argc == 1)
		map = read_console();
	else if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			map = read_file(argv[i]);
			i++;
		}
	}




	

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("(%c)", map[i][j]);
		}
		printf("\n");
	}
	
	// FREE
	for (int i = 0; i < 3; i++)
	{
		free(map[i]);
	}
	free(map);
	// FREE
}
