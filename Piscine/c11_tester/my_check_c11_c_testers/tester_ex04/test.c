/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:22:15 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/17 15:51:19 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_current_bigger_than_next(int current, int next)
{
	if (current < next)
		return (-1);
	else if (current > next)
		return (1);
	return (0);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int));

int main(void)
{
	int tab1[10] = {1, 2, 3, 4, 5, 6 ,7, 8, 9, 10};
	int tab2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int tab3[8] = {-2147483648, 2, 3, 4, 5, 6, 9, 2147483647};
	printf("res1 = %d\n", ft_is_sort(tab1, 10, &is_current_bigger_than_next));
	printf("res2 = %d\n", ft_is_sort(tab2, 10, &is_current_bigger_than_next));
	printf("res3 = %d\n", ft_is_sort(tab3, 8, &is_current_bigger_than_next));
}
