/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:12:39 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/10 12:13:07 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	skip_spaces(char *s)
{
	int	i;
	int	pm_start;

	pm_start = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == '\t' || s[i] == '\n' || s[i] == '\v') && !pm_start)
			i++;
		else if ((s[i] == '\f' || s[i] == '\r' || s[i] == ' ') && !pm_start)
			i++;
		else if (s[i] == '-' || s[i] == '+')
		{
			pm_start = 1;
			i++;
		}
		else
			break ;
	}
	return (i);
}

int	minus_counter(int minus_count, char *str, int i)
{
	if (*(str + i) == '-')
		minus_count++;
	return (minus_count);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	is_base_good(char *b, int bs)
{
	int	i;
	int	j;

	if (b[bs] == '+' || b[bs] == '-' || b[bs] == '\t' || b[bs] == '\n')
		return (0);
	else if (b[bs] == '\v' || b[bs] == '\f' || b[bs] == '\r' || b[bs] == ' ')
		return (0);
	i = 0;
	while (i < bs - 1)
	{
		j = i + 1;
		while (j < bs)
		{
			if (b[i] == b[j] || b[i] == '+' || b[i] == '-' || b[i] == '\t')
				return (0);
			else if (b[i] == '\n' || b[i] == '\v' || b[i] == '\f')
				return (0);
			else if (b[i] == '\r' || b[i] == ' ' || bs <= 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus_count;
	int	res;
	int	digit_started;

	digit_started = 0;
	minus_count = 0;
	res = 0;
	i = skip_spaces(str);
	is_base_good(base, ft_strlen(base));
	while (*(str + i) != '\0')
	{
		if ((*(str + i) == '-' || *(str + i) == '+') && !digit_started)
			minus_count = minus_counter(minus_count, str, i);
		else if (*(str + i) >= 32 && *(str + i) <= 126)
		{
			res = res * 10 + (*(str + i));
			digit_started = 1;
		}
		i++;
	}
	if ((minus_count % 2) && minus_count > 0)
		res *= -1;
	return (res);
}
