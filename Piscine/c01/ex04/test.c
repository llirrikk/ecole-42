/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:42:48 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/05 15:43:40 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = INT_MAX;
	b = 5194;
	printf("a=%d, b=%d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a=%d, b=%d\n", a, b);
}
