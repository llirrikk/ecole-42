/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling_str_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:26:50 by sserwyn           #+#    #+#             */
/*   Updated: 2021/11/24 13:52:25 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handling_str_args(char spec, va_list args, int *count_symbols)
{
	char	*converted_to_str;

	if (spec == 'd' || spec == 'i')
		converted_to_str = ft_itoa(va_arg(args, int));
	else if (spec == 'u')
		converted_to_str = ft_ltoa(va_arg(args, unsigned int));
	else if (spec == 'p')
		converted_to_str = pointer_to_str(va_arg(args, unsigned long));
	ft_putstr(converted_to_str, count_symbols);
	free(converted_to_str);
}
