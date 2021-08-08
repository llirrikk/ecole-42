/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:34:27 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/08 14:50:51 by satronac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	top(int j, int x)
{
	if (j == 0)
		ft_putchar('A');
	else if (j > 0 && j < x - 1)
		ft_putchar('B');
	else
		ft_putchar('C');
}

void	left(int i, int y)
{
	if (i > 0 && i < y - 1)
		ft_putchar('B');
}

void	bottom(int j, int x)
{
	if (j == 0)
		ft_putchar('C');
	else if (j > 0 && j < x - 1)
		ft_putchar('B');
	else
		ft_putchar('A');
}

void	right(int i, int y)
{
	if (i > 0 && i < y - 1)
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0)
				top(j, x);
			else if (i == y - 1)
				bottom(j, x);
			else if (j == 0)
				left(i, y);
			else if (j == x - 1)
				right(i, y);
			if (i > 0 && j > 0 && i < y - 1 && j < x - 1)
				ft_putchar(' ');
			j++;
		}
		if (x != 0)
			ft_putchar('\n');
		i++;
	}
}
