/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:28:34 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/17 14:33:58 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_foreach(int *tab, int length, void(*f)(int));

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	digit_counter(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	if_int_min(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	int	count_10;
	int	i;

	i = 0;
	count_10 = 1;
	nb = if_int_min(nb);
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	while (i < digit_counter(nb) - 1)
	{
		count_10 *= 10;
		i++;
	}
	while (count_10 > 0)
	{
		ft_putchar((nb / count_10) - ((nb / count_10 / 10) * 10) + '0');
		count_10 /= 10;
	}
}

int main(void)
{
	int tab[10] = {10, 5, 1, -4, 2147483647, -2147483648, 0, 0, 12455, 21};
	ft_foreach(tab, 10, &ft_putnbr);
}
