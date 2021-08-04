/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:52:03 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/04 15:52:04 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	_ft_putcomma(void)
{
	char	comma;
	char	space;

	comma = ',';
	space = ' ';
	ft_putchar(comma);
	ft_putchar(space);
}

void	ft_print_comb(void)
{
	int	a[3];

	a[0] = '0';
	while (a[0] <= '7')
	{
		a[1] = a[0] + 1;
		while (a[1] <= '8')
		{
			a[2] = a[1] + 1;
			while (a[2] <= '9')
			{
				ft_putchar(a[0]);
				ft_putchar(a[1]);
				ft_putchar(a[2]);
				if (!(a[0] == '7' && a[1] == '8' && a[2] == '9'))
					_ft_putcomma();
				a[2]++;
			}
			a[1]++;
		}
		a[0]++;
	}
}
