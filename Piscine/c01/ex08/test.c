/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:00:34 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/05 17:01:04 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

void	my_print_array(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", *(tab + i));
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int	array[] = {42, 21, 551, 595, INT_MAX, 0, -1, INT_MIN};
	int	size = 8;
	printf("test #1\nnormal:\t\t");
	my_print_array(array, size);
	ft_sort_int_tab(array, size);
	printf("reversed:\t");
	my_print_array(array, size);

	int	array2[] = {42};
	int	size2 = 1;
	printf("\ntest #2\nnormal:\t\t");
	my_print_array(array2, size2);
	ft_sort_int_tab(array2, size2);
	printf("reversed:\t");
	my_print_array(array2, size2);
	return (0);
}
