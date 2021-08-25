/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:32:48 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/25 12:25:00 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_realloc(char *old, char ch);
void	first_line_checker(char *line);
int		number_1st_line(char *line);
void	map_checker(char **map, char *fline);
void	map_error_exit(void);
void	str_init(char **str);
int		ft_strlen(char *str);

char	*get_header(int fd)
{
	char	ch;
	char	*first_line;

	str_init(&first_line);
	while (read(fd, &ch, 1) != 0 && ch != '\n')
		first_line = ft_realloc(first_line, ch);
	return (first_line);
}

char	**get_map(int fd, int hight, int length)
{
	char	**map;
	int		i;
	char	ch;

	while (read(fd, &ch, 1) != 0 && ch != '\n') // skip header
	{
	}
	map = (char **)malloc(sizeof(char *) * hight);
	i = 0;
	while (i < hight)
	{
		map[i] = (char *)malloc(sizeof(char) * (length + 1));
		i++;
	}
	i = 0;
	while (read(fd, map[i], length + 1) != 0)
	{
		map[i][length] = '\0'; // remove '\n'
		i++;
	}
	return (map);
}

int	get_map_1st_line_length(int fd)
{
	char	ch;
	int		first_line_length;

	first_line_length = 0;
	while (read(fd, &ch, 1) != 0 && ch != '\n')
		first_line_length++;
	return (first_line_length);
}

char	**read_file(char *file_name, char **header)
{
	int		fd;
	char	**map;
	int		map_1st_line_length;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		map_error_exit();
	*header = get_header(fd);
	map_1st_line_length = get_map_1st_line_length(fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		map_error_exit();
	map = get_map(fd, number_1st_line(*header), map_1st_line_length);
	close(fd);
	return (map);
}

// ОШИБКА ЕСЛИ МАР ЕРРОР