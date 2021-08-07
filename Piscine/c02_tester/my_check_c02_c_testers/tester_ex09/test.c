/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:54:10 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 13:54:23 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	*test1;
	char	*test2;
	char	*test3;
	char	*test4;
	char	*test5;
	char	*test6;

	char    c1[] = {"salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un"};
	char    c2[] = {"lorem ipsum dolor sit amet, consectetur adipiscing elit"};
	char    c3[] = {"metus dui, feugiat non mauris vel, Suscipit varius elit"};
	char    c4[] = {"35 I  FNT$#$I^&TF$&#NTIF(N&)(*@UN*FY)@&"};
	char    c5[] = {""};
	char    c6[] = {" \n"};

	test1 = ft_strcapitalize(c1);
	test2 = ft_strcapitalize(c2);
	test3 = ft_strcapitalize(c3);
	test4 = ft_strcapitalize(c4);
	test5 = ft_strcapitalize(c5);
	test6 = ft_strcapitalize(c6);
	printf("test1: %s\n", test1);
	printf("test2: %s\n", test2);
	printf("test3: %s\n", test3);
	printf("test4: %s\n", test4);
	printf("test5: %s\n", test5);
	printf("test6: %s\n", test6);
}
