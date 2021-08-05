/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:33:46 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/05 15:36:12 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = INT_MAX;
	b = 31276;
	ft_div_mod(a, b, &div, &mod);
	printf("a=%d, b=%d\n", a, b);
	printf("div=%d, mod=%d\n", div, mod);
	return (0);
}
