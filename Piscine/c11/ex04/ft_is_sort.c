/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:22:05 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/18 19:16:36 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	is_sort_from_small;
	int	is_sort_from_big;

	is_sort_from_small = 1;
	is_sort_from_big = 1;
	i = 0;
	while (i < length - 1 && is_sort_from_small)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			is_sort_from_small = 0;
		i++;
	}
	i = 0;
	while (i < length - 1 && is_sort_from_big)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			is_sort_from_big = 0;
		i++;
	}
	return (is_sort_from_big || is_sort_from_small);
}
