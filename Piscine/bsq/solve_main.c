/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:13:35 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/24 16:52:33 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // <----------------

int		ft_strlen(char *str);
int		number_1st_line(char *line);

int	get_map_length(char **map)
{
	return (ft_strlen(map[0]));
}

int	get_map_height(char *first_line)
{
	return(number_1st_line(first_line));
}

char	get_map_empty(char *first_line)
{
	return (first_line[ft_strlen(first_line) - 3]);
}

char	get_map_obstacle(char *first_line)
{
	return (first_line[ft_strlen(first_line) - 2]);
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

int	**map_to_cash(char **map, char *first_line)
{
	int		**cash;
	int		i;
	int		j;
	char	obstacle;
	char	empty;
	int		min_of_3;
	int		cash_max;
	int		max_index[2];
	int		corner_found;
	int		temp;

	empty = get_map_empty(first_line);
	obstacle = get_map_obstacle(first_line);

	cash = (int **)malloc(sizeof(int *) * get_map_height(first_line));
	i = 0;
	while (i < get_map_height(first_line))
	{
		cash[i] = (int *)malloc(sizeof(int) * get_map_length(map));
		i++;
	}

	cash_max = 0;
	

	i = 0;
	while (i < get_map_height(first_line))
	{
		j = 0;
		while (j < get_map_length(map))
		{
			if (i == 0 || j == 0)
			{
				if (map[i][j] == obstacle)
					cash[i][j] = 0;
				else
					cash[i][j] = 1;
			}
			else
			{
				if (map[i][j] == obstacle)
					cash[i][j] = 0;
				else
				{
					min_of_3 = get_min_of_3(cash[i][j-1], cash[i-1][j-1], cash[i-1][j]);
					cash[i][j] = min_of_3 + 1;
				}
			}

			if (cash_max < cash[i][j])
			{
				cash_max = cash[i][j];
				max_index[0] = i;
				max_index[1] = j;
			}
			j++;
		}
		i++;
	}

	// printf("\n----------START----------\n");
	// i = 0;
	// while (i < get_map_height(first_line))
	// {
	// 	j = 0;
	// 	while (j < get_map_length(map))
	// 	{
	// 		printf("%c", map[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }


	// printf("\n----------CASH-------------\n");
	// i = 0;
	// while (i < get_map_height(first_line))
	// {
	// 	j = 0;
	// 	while (j < get_map_length(map))
	// 	{
	// 		printf("%d", cash[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }

	corner_found = 0;
	temp = cash_max;
	i = 0;
	while (i < get_map_height(first_line))
	{
		j = 0;
		while (j < get_map_length(map))
		{

			if (max_index[0] - (cash_max - 1) == i && max_index[1] - (cash_max - 1) == j)
				corner_found = 1;
			if (corner_found && (ft_abs(max_index[0] - i) < cash_max && ft_abs(max_index[1] - j) < cash_max) && temp > 0
									&& (max_index[0] >= i))
			{
				temp--;
				printf("x");
			}
			else
				printf("%c", map[i][j]);
			j++;
		}
		temp = cash_max;
		printf("\n");
		i++;
	}





	return (NULL);
}
