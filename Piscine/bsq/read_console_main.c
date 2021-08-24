/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_console_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:18:13 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/24 13:34:59 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_realloc(char *old, char ch);
void	first_line_checker(char *line);
int		number_1st_line(char *line);
void	map_checker(char **map, char *fline);

void	first_line_and_map_checker(char **map, char *fline)
{
	first_line_checker(fline);
	map_checker(map, fline);
}

void	str_init(char **str);

void	str_line_count_init(int *line_count, char **l, int is_inc)
{
	if (is_inc)
		*line_count = *line_count + 1;
	else
		*line_count = 0;
	str_init(l);
}


char	**read_console(char **first_line)
{
	int		line_count;
	char	ch;
	char	*l[2];
	char	**map;

	str_line_count_init(&line_count, &l[0], 0);
	while (read(1, &ch, 1) != 0)
	{
		if (ch != '\n')
			l[0] = ft_realloc(l[0], ch);
		else
		{
			if (line_count == 0)
			{
				l[1] = l[0];
				map = (char **)malloc(sizeof(char *) * (number_1st_line(l[1])));
			}
			else
				map[line_count - 1] = l[0];
			str_line_count_init(&line_count, &l[0], 1);
			if (line_count - 1 == number_1st_line(l[1]))
				break ;
		}
	}
	first_line_and_map_checker(map, l[1]);
	*first_line = l[1];
	return (map);
}
