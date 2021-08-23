/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_console_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:18:13 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/23 19:29:43 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_realloc(char *old, char ch);
void	first_line_checker(char *line);
int		number_1st_line(char *line);
void	map_checker(char **map, char *fline);

void	str_init(char **str);

char	**read_console(void)
{
	int		ret;
	int		line_count;
	char	ch;
	char	*line;
	char	*l1st;
	char	**map;

	line_count = 0;
	str_init(&line);
	ret = read(1, &ch, 1);
	while (ret != 0)
	{
		if (ch != '\n')
			line = ft_realloc(line, ch);
		else
		{
			if (line_count == 0)
			{
				l1st = line;
				map = (char **)malloc(sizeof(char *) * (number_1st_line(l1st)));
			}
			else
				map[line_count - 1] = line;
			line_count++;
			str_init(&line);
			if (line_count - 1 == number_1st_line(l1st))
				break ;
		}
		ret = read(1, &ch, 1);
	}
	first_line_checker(l1st);
	map_checker(map, l1st);
	return (map);
}
