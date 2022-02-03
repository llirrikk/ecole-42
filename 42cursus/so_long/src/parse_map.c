/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:33:03 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/31 19:29:00 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*skip_first_nlines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static int	skip_last_nlines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strlen_without_last_nl(line) > 0)
		{
			free(line);
			close(fd);
			return (RECTANGULAR_MAP_ERROR);
		}
		line = get_next_line(fd);
	}
	return (0);
}

typedef struct s_read_file
{
	int		fd;
	char	*line;
}	t_read_file;

static int	detect_map_height(t_map *map, char *ber_file)
{
	t_read_file	f;

	map->height = 0;
	f.fd = open(ber_file, O_RDONLY);
	f.line = skip_first_nlines(f.fd);
	while (f.line != NULL)
	{
		map->width = ft_strlen_without_last_nl(f.line);
		free(f.line);
		(map->height)++;
		f.line = get_next_line(f.fd);
		if (f.line != NULL && f.line[0] == '\n')
			break ;
		if (f.line != NULL && map->width != ft_strlen_without_last_nl(f.line))
		{
			free(f.line);
			return (RECTANGULAR_MAP_ERROR);
		}
	}
	if (skip_last_nlines(f.fd) == RECTANGULAR_MAP_ERROR)
		return (RECTANGULAR_MAP_ERROR);
	close(f.fd);
	map->array = (char **)malloc(sizeof(char *) * map->height);
	return (0);
}

int	parse_ber_file(t_map *map, char *ber_file)
{
	int			height;
	t_read_file	file;
	int			detect_map_height_error;

	detect_map_height_error = detect_map_height(map, ber_file);
	if (detect_map_height_error != 0)
		return (detect_map_height_error);
	if (map->array == NULL)
		return (MALLOC_ERROR);
	height = 0;
	file.fd = open(ber_file, O_RDONLY);
	file.line = skip_first_nlines(file.fd);
	while (height < map->height)
	{
		map->array[height] = (char *)malloc(sizeof(char) * (map->width + 2));
		if (map->array[height] == NULL)
			return (MALLOC_ERROR);
		ft_strcpy(map->array[height], file.line);
		map->array[height][map->width] = '\0';
		free(file.line);
		height++;
		file.line = get_next_line(file.fd);
	}
	close(file.fd);
	return (0);
}
