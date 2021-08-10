/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:07:10 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/09 16:07:25 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	ft_putnbr_base(2147483647, "0123456789ABCDEF");
	ft_putnbr_base(-4, "AB");
	ft_putnbr_base(234325, "ABA");
	ft_putnbr_base(0, "AB");
	ft_putnbr_base(0, "+B");
	ft_putnbr_base(0, "A+");
	ft_putnbr_base(-0, "0123456789");
	ft_putnbr_base(236321432, "0123456789");
	ft_putnbr_base(-3526426, "0123456789");
	ft_putnbr_base(624, "0123+56789");
	ft_putnbr_base(42, "012345678T");
}
