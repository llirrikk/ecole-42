/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:20:58 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/18 19:43:43 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	tab_size;

	tab_size = 0;
	while (tab[tab_size] != (void *)0)
		tab_size++;
	i = 0;
	while (i < tab_size - 1)
	{
		j = i + 1;
		while (j < tab_size)
		{
			if (cmp(tab[i], tab[j]) > 0)
				ft_swap_str(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
