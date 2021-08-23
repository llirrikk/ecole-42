/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:10 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/23 19:11:02 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // <----------------

#define TRUE 1
#define FALSE 0

char	*ft_realloc(char *old, char ch);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		is_digit(char c);
int		is_printable(char c);
void	map_error_exit(void);

void	first_line_checker(char *line);
void	oef_check(char obstacle, char empty, char full);
int		number_1st_line(char *line);

void	str_init(char **str)
{
	*str = malloc(sizeof(char));
	*str[0] = '\0';
}

void	map_lines_length(char **map, int strs_count)
{
	int	i;
	int	length;

	length = ft_strlen(map[0]);
	i = 0;
	while (i < strs_count)
	{
		if (length != ft_strlen(map[i]))
			map_error_exit();
		i++;
	}
}

void	map_checker(char **map, char *fline)
{
	int	i;
	int	j;
	int	count_pixels_o[2];

	count_pixels_o[0] = 0;
	count_pixels_o[1] = 0;
	map_lines_length(map, number_1st_line(fline));
	i = 0;
	while (i < number_1st_line(fline))
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == fline[ft_strlen(fline) - 2])
				count_pixels_o[1]++;
			if (map[i][j] != fline[ft_strlen(fline) - 3]
				&& map[i][j] != fline[ft_strlen(fline) - 2])
				map_error_exit();
			count_pixels_o[0]++;
			j++;
		}
		i++;
	}
	if (count_pixels_o[0] == count_pixels_o[1])
		map_error_exit();
}

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

int	main(int argc, char **argv)
{
	char	**map;

	if (argc == 1)
		map = read_console();
	else if (argc > 1)
		//read_file(argc, argv);
	(void) argv;
}
