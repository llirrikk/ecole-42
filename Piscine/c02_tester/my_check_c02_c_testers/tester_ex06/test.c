/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:54:56 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 12:55:09 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;
	int	test5;
	int	test6;

	test1 = ft_str_is_printable("*&@#YFN*&@N*&#\40T&*FTNG@IICG @IN@F O@fg g2 FI 2T#F*^FT @&^ giy4g`~");
	test2 = ft_str_is_printable("\176fdweewgw");
	test3 = ft_str_is_printable("52366\17723623");
	test4 = ft_str_is_printable("35 I  FNT$#$I^&TF$&#NTIF(N&)(*@UN*FY)@&\37");
	test5 = ft_str_is_printable("");
	test6 = ft_str_is_printable(" \106");
	printf("test1: %d\n", test1);
	printf("test2: %d\n", test2);
	printf("test3: %d\n", test3);
	printf("test4: %d\n", test4);
	printf("test5: %d\n", test5);
	printf("test6: %d\n", test6);
}
