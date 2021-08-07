/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:53:10 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 16:53:26 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	c1[] = {"Coucou\ntu vas bien ?"};
	char	c2[] = {"lorem ipsum dolor sit amet, consectetur adipiscing elit"};
	char	c3[] = {"\n\n\n\n\n\n\n\n\n\\\t\t\t\t\t\t\t\t\\"};
	char	c4[] = {"18240915891"};
	char	c5[] = {""};
	char	c6[] = {" \n"};

	ft_putstr_non_printable(c1);
	ft_putstr_non_printable(c2);
	ft_putstr_non_printable(c3);
	ft_putstr_non_printable(c4);
	ft_putstr_non_printable(c5);
	ft_putstr_non_printable(c6);
}
