/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:10:58 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/10 17:11:14 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb);

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
	while (i < 51)
	{
		printf("next prime from %d is %d (%s)\n", i, ft_find_next_prime(i), is_in_array(ft_find_next_prime(i), real_primes) ? "it's prime" : "it isn't prime <-------");
		i++;
	}
	
	printf("%d (%s)\n", ft_find_next_prime(2147483645), ft_find_next_prime(2147483645) == 2147483647 ? "OK" : "KO :( <-------");
}
