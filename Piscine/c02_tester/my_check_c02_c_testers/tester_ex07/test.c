/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:19:21 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 13:19:34 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char	*test1;
	char	*test2;
	char	*test3;
	char	*test4;
	char	*test5;
	char	*test6;

	char    c1[] = {"zergergoiueagbr"};
	char    c2[] = {"ffergerFEWFJio"};
	char    c3[] = {"523635233"};
	char    c4[] = {"35 I  FNT$#$I^&TF$&#NTIF(N&)(*@UN*FY)@&"};
	char    c5[] = {""};
	char    c6[] = {" \n"};

	test1 = ft_strupcase(c1);
	test2 = ft_strupcase(c2);
	test3 = ft_strupcase(c3);
	test4 = ft_strupcase(c4);
	test5 = ft_strupcase(c5);
	test6 = ft_strupcase(c6);
	printf("test1: %s\n", test1);
	printf("test2: %s\n", test2);
	printf("test3: %s\n", test3);
	printf("test4: %s\n", test4);
	printf("test5: %s\n", test5);
	printf("test6: %s\n", test6);
}
