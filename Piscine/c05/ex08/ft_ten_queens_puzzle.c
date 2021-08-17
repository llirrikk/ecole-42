/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:05:25 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/10 18:05:38 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// r1 - r2 = c1 - c2

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	my_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

int	check_if_queens_is_10(int queens, int count, int *line)
{
	int	k;

	if (queens == 10)
	{
		k = 0;
		while (k < 10)
		{
			ft_putchar(line[k] + '0');
			k++;
		}
		count = count + 1;
		ft_putchar('\n');
	}
	return (count);
}

void	start(int *line, int *count, int queens)
{
	int	i;
	int	j;

	*count = check_if_queens_is_10(queens, *count, line);
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < queens)
		{
			if (i == line[j] || my_abs(j - queens) == my_abs(line[j] - i))
				break ;
			j++;
		}
		if (j == queens)
		{
			line[queens] = i;
			start(line, count, queens + 1);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	line[10];
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 10)
	{
		line[i] = 0;
		i++;
	}
	start(line, &count, 0);
	return (count);
}
