/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:43:46 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/04 18:44:41 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int reverse_int(int x)
{
	int	y;

	y = 0;
	while (x != 0)
	{
		y = y * 10 + x % 10;
		x = x / 10;
	}
	return (y);
}

void	ft_putnbr(int nb)
{
	char	digit_to_char;
	int	current;
	int	reversed_int;

	reversed_int = reverse_int(nb);
	while (reversed_int != 0)
	{
		current = reversed_int % 10;
		digit_to_char = '0' + current;
		ft_putchar(digit_to_char);
		reversed_int /= 10;
	}
}
