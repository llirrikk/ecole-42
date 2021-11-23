/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:05:44 by sserwyn           #+#    #+#             */
/*   Updated: 2021/11/23 22:16:39 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_abs(long long int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

static size_t	ft_int_len(long long int n, int is_negative)
{
	size_t	size;

	size = 1;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	return (size + is_negative);
}

char	*ft_ltoa(long long int n)
{
	char	*result;
	size_t	n_len;
	int		is_negative;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	n_len = ft_int_len(n, is_negative);
	result = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!result)
		return ((char *) NULL);
	if (is_negative)
		result[0] = '-';
	result[n_len--] = '\0';
	if (n == 0)
	{
		result[n_len] = '0';
		return (result);
	}
	while (n)
	{
		result[n_len--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (result);
}
