/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:32:23 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 12:32:38 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;
	int	test5;
	int	test6;

	test1 = ft_str_is_lowercase("wffwrthtrhrtjrthrtvrtutrbntrne");
	test2 = ft_str_is_lowercase("vwegiuwhefHIUfewIOHFc");
	test3 = ft_str_is_lowercase("4f");
	test4 = ft_str_is_lowercase("ger@");
	test5 = ft_str_is_lowercase("");
	test6 = ft_str_is_lowercase(" ");
	printf("test1: %d\n", test1);
	printf("test2: %d\n", test2);
	printf("test3: %d\n", test3);
	printf("test4: %d\n", test4);
	printf("test5: %d\n", test5);
	printf("test6: %d\n", test6);
}