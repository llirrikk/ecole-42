/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:15:36 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/05 15:25:46 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = INT_MAX;
	b = INT_MIN;
	printf("a=%d, b=%d\n", a, b);
	ft_swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);
}
