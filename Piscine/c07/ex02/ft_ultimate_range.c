/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:30:55 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/12 16:30:56 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long int	i;
	long int	difference;
	int			*temp;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	difference = max - min;
	temp = (int *)malloc(sizeof(min) * (difference));
	if (NULL == temp)
		return (-1);
	difference = max - min;
	i = 0;
	while (min < max)
	{
		temp[i] = min;
		min++;
		i++;
	}
	*range = temp;
	if (difference > 2147483647 || difference < -2147483648)
		return (-1);
	return (difference);
}
