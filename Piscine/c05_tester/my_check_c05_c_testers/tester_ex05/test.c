/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:18:14 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/10 16:18:25 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb);

int	main(void)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		printf("sqrt(%d) = %d (%s)\n", i*i, ft_sqrt(i*i), ft_sqrt(i*i) == i ? "OK" : "KO :( <------");
		i++;
	}
	printf("sqrt(%d) = %d (%s)\n", 3, ft_sqrt(3), ft_sqrt(3) == 0 ? "OK" : "KO :( <------");
	printf("sqrt(%d) = %d (%s)\n", 5, ft_sqrt(5), ft_sqrt(26) == 0 ? "OK" : "KO :( <------");
	printf("sqrt(%d) = %d (%s)\n", 26, ft_sqrt(26), ft_sqrt(26) == 0 ? "OK" : "KO :( <------");

	printf("sqrt(%d) = %d (%s)\n", 2147003641, ft_sqrt(2147003641), ft_sqrt(2147003641) == 0 ? "OK" : "KO :( <------");
	printf("sqrt(%d) = %d (%s)\n", 2147483647, ft_sqrt(2147483647), ft_sqrt(2147483647) == 0 ? "OK" : "KO :( <------");
}
