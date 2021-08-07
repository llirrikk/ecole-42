/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:52:46 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 16:53:03 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	dec_to_hex_v2(char c)
{
	if (c == 10)
		return ('a');
	else if (c == 11)
		return ('b');
	else if (c == 12)
		return ('c');
	else if (c == 13)
		return ('d');
	else if (c == 14)
		return ('e');
	else
		return ('f');
}

char	dec_to_hex(char c)
{
	if (c > 9)
		return (dec_to_hex_v2(c));
	else if (c == 0)
		return ('0');
	else if (c == 1)
		return ('1');
	else if (c == 2)
		return ('2');
	else if (c == 3)
		return ('3');
	else if (c == 4)
		return ('4');
	else if (c == 5)
		return ('5');
	else if (c == 6)
		return ('6');
	else if (c == 7)
		return ('7');
	else if (c == 8)
		return ('8');
	else
		return ('9');
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	t;

	i = 0;
	while (*(str + i) != '\0')
	{
		t = *(str + i);
		if ((t >= 0 && t <= 31) || t == 127)
		{
			ft_putchar('\\');
			ft_putchar(dec_to_hex(t / 16));
			ft_putchar(dec_to_hex(t % 16));
		}
		else
		{
			ft_putchar(t);
		}
		i++;
	}
}
