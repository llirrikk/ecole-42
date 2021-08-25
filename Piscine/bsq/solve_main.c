/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:13:35 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/25 13:46:27 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // <----------------

void	ft_putchar(char c);
int		ft_strlen(char *str);
int		number_1st_line(char *line);

int	get_map_length(char **map)
{
	return (ft_strlen(map[0]));
}

char	get_map_empty(char *first_line)
{
	return (first_line[ft_strlen(first_line) - 3]);
}

char	get_map_obstacle(char *first_line)
{
	return (first_line[ft_strlen(first_line) - 2]);
}

char	get_map_full(char *first_line)
{
	return (first_line[ft_strlen(first_line) - 1]);
}

int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	return (n * (-1));
}

int	get_min_of_3(int left, int left_top, int top)
{
	int	min_of_3;

	min_of_3 = 2147483647;
	if (left < min_of_3)
		min_of_3 = left;
	if (left_top < min_of_3)
		min_of_3 = left_top;
	if (top < min_of_3)
		min_of_3 = top;
	return (min_of_3);
}


void	print_result(char **map, char *first_line, int cash_max, int *max_index)
{
	int corner_found;
	int temp;
	int	i;
	int	j;

	corner_found = 0;
	temp = cash_max;
	i = -1;
	while (++i < number_1st_line(first_line))
	{
		j = -1;
		while (++j < get_map_length(map))
		{

			if (max_index[0] - (cash_max - 1) == i && max_index[1] - (cash_max - 1) == j)
				corner_found = 1;
			if (corner_found && (ft_abs(max_index[0] - i) < cash_max && ft_abs(max_index[1] - j) < cash_max) && temp > 0
									&& (max_index[0] >= i))
			{
				temp--;
				ft_putchar(get_map_full(first_line));
			}
			else
				ft_putchar(map[i][j]);
		}
		temp = cash_max;
		ft_putchar('\n');
	}
}

int	get_cash_max(int *cash_max, int cash)
{
	if (*cash_max < cash)
	{
		*cash_max = cash;
		return (1);
	}
	return (0);
}

void	if_i_j_is_0(char **map, int **cash, char *first_line, int i, int j)
{
	if (i == 0 || j == 0)
	{
		if (map[i][j] == get_map_obstacle(first_line))
			cash[i][j] = 0;
		else
			cash[i][j] = 1;
	}
	else
	{
		if (map[i][j] == get_map_obstacle(first_line))
			cash[i][j] = 0;
		else
			cash[i][j] = get_min_of_3(cash[i][j-1], cash[i-1][j-1], cash[i-1][j]) + 1;
	}
}

void	get_cash_max_index(int *max_i, int *max_j, int i, int j)
{
	*max_i = i;
	*max_j = j;
}

void	solver(char **map, char *first_line)
{
	int		**cash;
	int		i;
	int		j;
	int		cash_max;
	int		max_index[2];

	cash = (int **)malloc(sizeof(int *) * number_1st_line(first_line));
	i = -1;
	while (++i < number_1st_line(first_line))
		cash[i] = (int *)malloc(sizeof(int) * get_map_length(map));
	cash_max = 0;
	i = -1;
	while (++i < number_1st_line(first_line))
	{
		j = -1;
		while (++j < get_map_length(map))
		{
			if_i_j_is_0(map, cash, first_line, i, j);
			if (get_cash_max(&cash_max, cash[i][j]))
				get_cash_max_index(&max_index[0], &max_index[1], i, j);
		}
	}
	print_result(map, first_line, cash_max, max_index);
}
