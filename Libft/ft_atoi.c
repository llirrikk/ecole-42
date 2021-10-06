/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:53:21 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/06 22:22:01 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	my_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0' && my_isspace(*(str + i)))
		i++;
	return (i);
}

static int	minus_counter(int minus_count, char *str, int i)
{
	if (*(str + i) == '-')
		minus_count++;
	return (minus_count);
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus_count;
	int	res;
	int	digit_started;

	digit_started = 0;
	minus_count = 0;
	res = 0;
	i = skip_spaces(str);
	while (*(str + i) != '\0')
	{
		if ((*(str + i) == '-' || *(str + i) == '+') && !digit_started)
			minus_count = minus_counter(minus_count, str, i);
		else if (is_digit(*(str + i)))
		{
			res = res * 10 + (*(str + i) - 48);
			digit_started = 1;
		}
		else
			break ;
		i++;
	}
	if ((minus_count % 2) && minus_count > 0)
		res *= -1;
	return (res);
}
