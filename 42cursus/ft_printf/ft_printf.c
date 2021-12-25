/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:56:01 by sserwyn           #+#    #+#             */
/*   Updated: 2021/12/25 16:16:27 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handling_str_args(char spec, va_list args, int *c_syms);

void	parse_spec(char spec, va_list args, int *c_symbs)
{
	if (spec == 'c')
		ft_putchar(va_arg(args, int), c_symbs);
	else if (spec == '%')
		ft_putchar('%', c_symbs);
	else if (spec == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", c_symbs);
	else if (spec == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", c_symbs);
	else if (spec == 's')
		ft_putstr(va_arg(args, char *), c_symbs);
	else if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'p')
		ft_handling_str_args(spec, args, c_symbs);
}

void	parse_input(const char *input, va_list args, int *count_symbols)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (input[i] != '%')
			ft_putchar(input[i], count_symbols);
		else
		{
			parse_spec(input[i + 1], args, count_symbols);
			i++;
		}
		i++;
	}	
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count_symbols;

	va_start(args, input);
	count_symbols = 0;
	parse_input(input, args, &count_symbols);
	va_end(args);
	return (count_symbols);
}
