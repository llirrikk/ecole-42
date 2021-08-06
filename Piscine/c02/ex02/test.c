/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:03:10 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/06 21:03:28 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	main(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;
	
	test1 = ft_str_is_alpha("wffwe");
	test2 = ft_str_is_alpha("vwegiuwhefHIUfewIOHFc");
	test3 = ft_str_is_alpha("4f");
	test4 = ft_str_is_alpha("ger@");

	printf("test1: %d\n", test1);
	printf("test2: %d\n", test2);
	printf("test3: %d\n", test3);
	printf("test4: %d\n", test4);
}
