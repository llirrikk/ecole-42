/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:48:17 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 12:48:31 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;
	int	test5;
	int	test6;

	test1 = ft_str_is_uppercase("IUHLVWJKRHVIUWEHILUFHEIUFHBOUIWE");
	test2 = ft_str_is_uppercase("FEFWEFKUGKHJiuhfweIUEHFWF");
	test3 = ft_str_is_uppercase("4f");
	test4 = ft_str_is_uppercase("ger@");
	test5 = ft_str_is_uppercase("");
	test6 = ft_str_is_uppercase(" ");
	printf("test1: %d\n", test1);
	printf("test2: %d\n", test2);
	printf("test3: %d\n", test3);
	printf("test4: %d\n", test4);
	printf("test5: %d\n", test5);
	printf("test6: %d\n", test6);
}