/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:32:48 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/23 20:52:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_realloc(char *old, char ch);
void	first_line_checker(char *line);
int		number_1st_line(char *line);
void	map_checker(char **map, char *fline);
void	map_error_exit(void);
void	str_init(char **str);

char	**read_file(char *file_name)
{
	int		fd;
	int		line_count;
	char	ch;
	char	*line;
	char	*l1st;
	char	**map;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		map_error_exit();
	line_count = 0;
	str_init(&line);
	while (read(fd, &ch, 1) != 0)
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
	}
	close(fd);
	first_line_checker(l1st);
	map_checker(map, l1st);
	return (map);
}

// ОШИБКА ЕСЛИ МАР ЕРРОР