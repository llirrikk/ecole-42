/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:33:04 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/10 16:33:15 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_is_prime(int nb);

int	is_in_array(int nb, int array[])
{
	int	i;

	i = 0;
	while (i < 39)
	{
		if (nb == array[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(void)
{
	int	i;
	int	real_primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173};

	i = -5;
	while (i < 21)
	{
		printf("%d - %s (%s)\n", i, ft_is_prime(i) ? "prime" : "not prime", ft_is_prime(i) == is_in_array(i, real_primes) ? "OK" : "KO :( <-----");
		i++;
	}

	printf("%d - %s (%s)\n", 2147483647, ft_is_prime(2147483647) ? "prime" : "not prime", ft_is_prime(2147483647) ? "OK" : "KO :( <-----");
	printf("%d - %s (%s)\n", 2147483646, ft_is_prime(2147483646) ? "prime" : "not prime", ft_is_prime(2147483646) ? "KO :( <-----" : "OK");
	printf("%d - %s (%s)\n", INT_MIN, ft_is_prime(INT_MIN) ? "prime" : "not prime", ft_is_prime(INT_MIN) ? "KO :( <-----" : "OK");
}
