/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:22:53 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/10 15:23:09 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb == 0)
		return (1);
	else if (nb == 1)
		return (1);
	else if (nb < 0)
		return (0);
	else
	{
		res = 2;
		while (nb > 2)
		{
			res = res * nb;
			nb--;
		}
	}
	return (res);
}

int	ft_recursive_factorial(int nb);

int	main(void)
{
	int	i;

	i = -5;
	while (i < 13)
	{
		printf("%d! = %d (%s)\n", i, ft_recursive_factorial(i), ft_iterative_factorial(i) == ft_recursive_factorial(i) ? "OK" : "KO :( <-------");
		i++;
	}
}
