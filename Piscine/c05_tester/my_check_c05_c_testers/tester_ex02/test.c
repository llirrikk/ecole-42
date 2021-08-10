/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:33:25 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/10 15:33:37 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

int	ft_iterative_power(int nb, int power);

int	main(void)
{
	int	i;

	i = -2;
	while (i < 11)
	{
		if (i < 0)
			printf("%d^(%d) = %d (%s)\n", 16 - i, i, ft_iterative_power(16 - i, i), ft_iterative_power(16 - i, i) == 0 ? "OK" : "KO :( <-------");
		else
			printf("%d^(%d) = %d (%s)\n", i, 16 - i, ft_iterative_power(i, 16 - i), (int)pow(i, 16 - i) == ft_iterative_power(i, 16 - i) ? "OK" : "KO :( <-------");
		i++;
	}
	printf("%d^(%d) = %d (%s)\n", 0, 0, ft_iterative_power(0, 0), 1 == ft_iterative_power(0, 0) ? "OK" : "KO :( <-------");
	i = 5;
	while (i < 8)
	{
		printf("%d^(%d) = %d (%s)\n", i, 0, ft_iterative_power(i, 0), ft_iterative_power(i, 0) == 1 ? "OK" : "KO :( <-------");
		i++;
	}
}
