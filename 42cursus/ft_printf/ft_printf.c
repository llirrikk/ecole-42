/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:56:01 by sserwyn           #+#    #+#             */
/*   Updated: 2021/11/24 14:20:00 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "ft_printf.h"

void	ft_handling_str_args(char spec, va_list args, int *count_symbols);

void	parse_spec(char spec, va_list args, int *count_symbols)
{
	if (spec == 'c')
		ft_putchar(va_arg(args, int), count_symbols);
	else if (spec == '%')
		ft_putchar('%', count_symbols);
	else if (spec == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", count_symbols);
	else if (spec == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", count_symbols);
	else if (spec == 's')
		ft_putstr(va_arg(args, char *), count_symbols);
	else if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'p')
		ft_handling_str_args(spec, args, count_symbols);
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
			if ((int) i - 1 == ft_strlen(input))
				{}// printf("ERROR %% is last char!\n");
			else
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

// #include <stdio.h>
// int	main(void)
// {
// 	ft_printf("this is the real number: %x\n", -1u);
// 	printf("this is the real number: %x\n", -1u);
// }
