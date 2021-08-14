/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:29:38 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/14 14:54:02 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*my_struct;

	my_struct = malloc((ac + 1) * sizeof(t_stock_str));
	if (my_struct == NULL || ac <= 0)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		my_struct[i].size = ft_strlen(av[i]);
		my_struct[i].str = malloc(sizeof(av[i]));
		if (my_struct[i].str == NULL)
			return (NULL);
		my_struct[i].copy = malloc(sizeof(av[i]));
		if (my_struct[i].copy == NULL)
			return (NULL);
		ft_strcpy(my_struct[i].str, av[i]);
		ft_strcpy(my_struct[i].copy, my_struct[i].str);
		i++;
	}
	my_struct[i].str = 0;
	return (my_struct);
}
