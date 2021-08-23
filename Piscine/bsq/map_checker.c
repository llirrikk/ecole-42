/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:13:36 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/23 19:16:48 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);
void	map_error_exit(void);
int		number_1st_line(char *line);

void	map_lines_length_checker(char **map, int strs_count)
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
	map_lines_length_checker(map, number_1st_line(fline));
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
