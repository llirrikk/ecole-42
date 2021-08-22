/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:01:44 by wdoctori          #+#    #+#             */
/*   Updated: 2021/08/22 20:31:48 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	propysksim(char	*str)
{
	int	f;

	f = 0;
	if (*str == '\n' || *str == '\t' || *str == '\f')
		f = 1;
	if (*str == '\r' || *str == '\v' || *str == ' ')
		f = 1;
	return (f);
}

int	numberChar(char	*num)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (propysksim(&num [i]))
		i++;
	if (!(num[i] >= '0' && num[i] <= '9'))
		return (-1);
	while ((num[i] >= '0' && num[i] <= '9') || num[i] == '.')
	{
		i++;
		b++;
		if (num[i] == '.')
		{
			return (-1);
		}
	}
	return (b);
}

char	*argv_cleaner(char	*str)
{
	int		i;
	int		b;
	int		s;
	char	*stroka;

	b = numberChar(str);
	if (b == -1)
		return (NULL);
	stroka = (char *)malloc(sizeof (*stroka) * (b + 1));
	i = 0;
	s = 0;
	while (propysksim(&str [i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*(stroka + s) = str[i];
		i++;
		s++;
	}
	*(stroka + s) = '\0';
	return (stroka);
}
