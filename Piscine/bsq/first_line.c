/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:21:32 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/25 15:44:28 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);
int		is_digit(char c);
int		is_printable(char c);

int	number_1st_line(char *line)
{
	int	i;
	int	number;

	number = 0;
	i = 0;
	while (i < ft_strlen(line) - 3)
	{
		if (!is_digit(line[i]))
			return (-1);
		number = number * 10 + line[i] - '0';
		i++;
	}
	return (number);
}

int	oef_check(char obstacle, char empty, char full)
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
		return (-1);
	return (0);
}

int	first_line_checker(char *line)
{
	int		i;
	char	map_e_o_f[3];

	if (ft_strlen(line) < 4)
		return (-1);
	i = 0;
	while (i < ft_strlen(line) - 3)
	{
		if (!is_digit(line[i]))
			return (-1);
		i++;
	}
	while (i < ft_strlen(line))
	{
		if (!is_printable(line[i]))
			return (-1);
		i++;
	}
	if (number_1st_line(line) == 0 || number_1st_line(line) == -1)
		return (-1);
	map_e_o_f[0] = line[ft_strlen(line) - 3];
	map_e_o_f[1] = line[ft_strlen(line) - 2];
	map_e_o_f[2] = line[ft_strlen(line) - 1];
	oef_check(map_e_o_f[0], map_e_o_f[1], map_e_o_f[2]);
	return (0);
}
