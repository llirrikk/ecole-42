/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:20:45 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/05 16:20:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

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

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	array[] = {0, 1, 2, 3, 4, 5, 6, 7, INT_MAX, 9, INT_MIN};
	int	size = 11;

	printf("test #1\nnatural:\t");
	my_print_array(array, size);
	ft_rev_int_tab(array, size);
	printf("reversed:\t");
	my_print_array(array, size);

	printf("\ntest #2\nnatural:\t");
	int array2[] = {42};
	int size2 = 1;

	my_print_array(array2, size2);
	ft_rev_int_tab(array2, size2);
	printf("reversed:\t");
	my_print_array(array2, size2);
	return (0);
}