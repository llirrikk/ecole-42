/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:31:17 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/12 16:31:19 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	*arr;

	printf("res = %d\n", ft_ultimate_range(&arr, -5, 5));
	for (int i = 0; i < 10; i++)
		printf("arr[%d] = %d\n", i, arr[i]);

	printf("res = %d ", ft_ultimate_range(&arr, 5, -5));
	printf("%s\n", arr == NULL ? "OK" : "KO <------");
	// for (int i = 0; i < 10; i++)
	// 	printf("arr[%d] = %d\n", i, arr[i]);
}
