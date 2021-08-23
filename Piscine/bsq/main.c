/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:10 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/23 17:51:25 by sserwyn          ###   ########.fr       */
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
void	ft_putstr_error(char *str);
int		ft_strlen(char *str);
int		is_digit(char c);
int		is_printable(char c);

void	str_init(char **str)
{
	*str = malloc(sizeof(char));
	*str[0] = '\0';
}

void	first_line_check(char *line)
{
	int	i;

	if (ft_strlen(line) < 4)
	{
		ft_putstr_error("map error\n");
		exit(1);
	}
	i = 0;
	while (i < ft_strlen(line) - 3)
	{
		if (!is_digit(line[i]))
		{
			ft_putstr_error("map error\n");
			exit(1);
		}
		i++;
	}
	while (i < ft_strlen(line))
	{
		if (!is_printable(line[i]))
		{
			ft_putstr_error("map error\n");
			exit(1);
		}
		i++;
	}
}

int	line_count_from_first_line(char *line)
{
	int	i;
	int	number;

	number = 0;
	i = 0;
	while (i < ft_strlen(line) - 3)
	{
		number = number * 10 + line[i] - '0';
		i++;
	}
	return (number);
}

void	oef_check(char obstacle, char empty, char full)
{
	int	is_error;

	is_error = 0;
	if (empty == obstacle)
		is_error = 1;
	else if (empty == full)
		is_error = 1;
	else if (obstacle == full)
		is_error = 1;
	if (is_error == 1)
	{
		ft_putstr_error("map error\n");
		exit(1);
	}
}

void	map_checker(char *line, char empty, char obstacle, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		if (line[i] != empty && line[i] != obstacle)
		{
			ft_putstr_error("map error\n");
			exit(1);
		}
		i++;
	}
}

char	**scan_console(void)
{
	int		ret;
	char	ch;
	char	*line;
	char	**map;
	int		line_count;
	int		map_e_o[2];
	int		number;

	line_count = 0;
	number = -1;
	str_init(&line);
	
	ret = read(1, &ch, 1);
	while (ret != 0)
	{
		if (ch != '\n')
		{
			line = ft_realloc(line, ch);
		}
		else
		{
			if (line_count == 0)
			{
				first_line_check(line);
				map_e_o[0] = line[ft_strlen(line) - 3];
				map_e_o[1] = line[ft_strlen(line) - 2];
				number = line_count_from_first_line(line);
				map = (char **)malloc(sizeof(char *) * (number));
				if (number == 0)
				{
					ft_putstr_error("map error\n");
					exit(1);
				}
				oef_check(map_e_o[0], map_e_o[1], line[ft_strlen(line) - 1]);
			}
			else
				map[line_count - 1] = line;
			line_count++;
			str_init(&line);
			if (line_count - 1 == number)
				break ;
		}
		ret = read(1, &ch, 1);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc == 1)
		map = scan_console();
	else if (argc > 1)
		//scan_map_files(argc, argv);
	(void) argv;
}
