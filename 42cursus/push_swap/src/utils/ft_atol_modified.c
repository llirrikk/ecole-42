/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_modified.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:53:21 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/05 17:03:12 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_isdigit(int c);

static int	my_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	return (c == '\f' || c == '\r' || c == ' ');
}

static int	sign_detection(int *sign, char str)
{
	*sign = 1;
	if (str == '-' || str == '+')
	{
		if (str == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

long int	ft_atol(const char *str)
{
	long long int	res;
	int				sign;

	while (my_isspace(*str))
		str++;
	str += sign_detection(&sign, *str);
	res = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (*str != '\0' && !ft_isdigit(*str))
		return ((long int)MAX_INT + 1);
	return (sign * res);
}
