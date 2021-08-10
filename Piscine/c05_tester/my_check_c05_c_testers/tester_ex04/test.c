/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:00:45 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/10 16:01:00 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index);

int	main(void)
{
	int	i;
	int	real_fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946};

	i = -3;
	while (i < 22)
	{
		if (i >= 0)
			printf("fib(%d) = %d (%s)\n", i, ft_fibonacci(i), ft_fibonacci(i) == real_fib[i] ? "OK" : "KO :( <------");
		else
			printf("fib(%d) = %d (%s)\n", i, ft_fibonacci(i), ft_fibonacci(i) == -1 ? "OK" : "KO :( <------");
		i++;
	}
}
