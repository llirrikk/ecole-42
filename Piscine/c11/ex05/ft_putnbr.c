/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:45:06 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/17 16:57:40 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

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
