/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:58:08 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/04 16:58:10 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	_ft_put_comma_and_space(void)
{
	char	comma;
	char	space;

	comma = ',';
	space = ' ';
	ft_putchar(comma);
	ft_putchar(space);
}

void	_ft_put_only_space(void)
{
	char	space;

	space = ' ';
	ft_putchar(space);
}

void	ft_print_comb2(void)
{
	int	numbers[2][2];
	int	counter_1;
	int	counter_2;

	counter_1 = 0;
	while (counter_1 <= 99)
	{
		counter_2 = counter_1 + 1;
		while (counter_2 <= 99)
		{
			numbers[0][0] = '0' + counter_1 / 10;
			numbers[0][1] = '0' + counter_1 % 10;
			numbers[1][0] = '0' + counter_2 / 10;
			numbers[1][1] = '0' + counter_2 % 10;
			ft_putchar(numbers[0][0]);
			ft_putchar(numbers[0][1]);
			_ft_put_only_space();
			ft_putchar(numbers[1][0]);
			ft_putchar(numbers[1][1]);
			if (!(counter_1 == 98 && counter_2 == 99))
				_ft_put_comma_and_space();
			counter_2++;
		}
		counter_1++;
	}
}
