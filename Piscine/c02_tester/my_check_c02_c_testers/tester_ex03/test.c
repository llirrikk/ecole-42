/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:54:10 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/06 21:54:27 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;
	int	test5;
	int	test6;

	test1 = ft_str_is_numeric("7536453467346");
	test2 = ft_str_is_numeric("-2147483648");
	test3 = ft_str_is_numeric("4 523");
	test4 = ft_str_is_numeric("gereg");
	test5 = ft_str_is_numeric("");
	test6 = ft_str_is_numeric("214748t364");

	printf("test1: %d\n", test1);
	printf("test2: %d\n", test2);
	printf("test3: %d\n", test3);
	printf("test4: %d\n", test4);
	printf("test5: %d\n", test5);
	printf("test6: %d\n", test6);
	
}
