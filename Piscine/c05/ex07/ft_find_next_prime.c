/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:09:09 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/10 17:10:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;
	int	old;
	int	is_next;

	if (nb < 2)
		return (2);
	is_next = 1;
	old = nb;
	while (1 == 1)
	{
		i = 2;
		while (i < nb && is_next)
		{
			if (nb % i == 0)
				is_next = 0;
			else
				is_next = 1;
			i++;
		}
		if (nb >= old && is_next)
			break ;
		nb++;
		is_next = 1;
	}
	return (nb);
}
