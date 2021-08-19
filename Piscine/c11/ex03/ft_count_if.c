/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:11:54 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/17 15:21:37 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			counter++;
		i++;
	}
	return (counter);
}
