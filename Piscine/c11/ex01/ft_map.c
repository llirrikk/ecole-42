/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:35:27 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/18 19:47:00 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*mapped;

	mapped = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		mapped[i] = f(tab[i]);
		i++;
	}
	return (mapped);
}
