/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:56:01 by sserwyn           #+#    #+#             */
/*   Updated: 2021/11/13 01:12:45 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	ft_putchar(char c);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);
char	*ft_itoa(int n);

void	parse_spec(char spec, va_list args)
{
	if (spec == 'c')
		ft_putchar(va_arg(args, int));
	else if (spec == 's')
		ft_putstr(va_arg(args, char *));
	else if (spec == 'd')
		ft_putstr(ft_itoa(va_arg(args, int)));
}

void	parse_input(const char *input, va_list args)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (input[i] != '%')
			ft_putchar(input[i]);
		else
		{
			if ((int) i - 1 == ft_strlen(input))
				printf("ERROR %% is last char!\n");
			else
				parse_spec(input[i + 1], args);
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
	parse_input(input, args);
	va_end(args);
	return (count_symbols);
}

int	main(void)
{
	ft_printf("hello, %s! %c! %d\n", "world", 'q', 228);
}
