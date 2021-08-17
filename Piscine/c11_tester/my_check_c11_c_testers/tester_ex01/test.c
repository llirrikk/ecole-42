/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:40:37 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/17 14:50:11 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (0);
	i = 2;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	*ft_map(int *tab, int length, int(*f)(int));

int main(void)
{
	int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *res = ft_map(tab, 10, &ft_is_prime);
	for (int i = 0; i < 10; i++)
		printf("%d ", res[i]);
}