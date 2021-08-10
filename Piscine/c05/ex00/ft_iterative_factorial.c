/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:45:59 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/10 13:46:10 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb == 0)
		return (1);
	else if (nb == 1)
		return (1);
	else if (nb < 0)
		return (0);
	else
	{
		res = 2;
		while (nb > 2)
		{
			res = res * nb;
			nb--;
		}
	}
	return (res);
}
