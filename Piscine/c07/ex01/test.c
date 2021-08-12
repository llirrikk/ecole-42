/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:55:44 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/12 15:56:00 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int	*result;
	int	i;
	int	from;
	int	to;

	from = -5;
	to = 13;
	i = 0;
	result = ft_range(from, to);
	while (i < to - from)
	{
		printf("%d ", result[i]);
		i++;
	}
	printf("\n");



	from = -200;
	to = -4;
	i = 0;
	result = ft_range(from, to);
	while (i < to - from)
	{
		printf("%d ", result[i]);
		i++;
	}
	printf("\n");


	from = 0;
	to = 0;
	result = ft_range(from, to);
	printf("%s ", result == NULL ? "NULL - OK!" : "KO <------");
	printf("\n");


	from = 14;
	to = 10;
	result = ft_range(from, to);
	printf("%s ", result == NULL ? "NULL - OK!" : "KO <------");
	printf("\n");
}
