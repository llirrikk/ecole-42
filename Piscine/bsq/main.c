/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:10 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/25 15:57:59 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TEMP_FILE_NAME "map.temp"

#include <stdio.h> // <----------------
#include <stdlib.h>

void	read_console(char *file_name);
char	**read_file(char *file_name, char **first_line);
void	ft_putstr_error(char *str);
int		data_handle(char **map, char *first_line);
void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int		i;
	char	*first_line;
	char	**map;

	map = NULL;
	first_line = NULL;
	if (argc == 1)
	{
		read_console(TEMP_FILE_NAME);
		map = read_file(TEMP_FILE_NAME, &first_line);
		if (map != NULL)
		{
			if (data_handle(map, first_line) == -1)
				ft_putstr_error("map error\n");
		}
	}
	else if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			map = read_file(argv[i], &first_line);
			if (map != NULL)
			{
				if (data_handle(map, first_line) == -1)
					ft_putstr_error("map error\n");
			}
			else
				ft_putstr_error("map error\n");
			if (i < argc - 1)
				ft_putchar('\n');
			i++;
		}
	}
}
