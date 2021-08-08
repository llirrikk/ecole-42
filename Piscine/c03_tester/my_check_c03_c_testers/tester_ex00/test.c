/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:32:27 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/08 15:32:43 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	str1[] = "inviep-g5";
	char	str2[] = "inviep-05";
	char	str3[] = "inviep";
	char	str4[] = "tr";
	char	str5[] = "";

	printf("is (%d == %d)? : %s\n", strcmp(str1, str1), ft_strcmp(str1, str1), ft_strcmp(str1, str1) == strcmp(str1, str1) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", strcmp(str1, str2), ft_strcmp(str1, str2), ft_strcmp(str1, str2) == strcmp(str1, str2) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", strcmp(str2, str1), ft_strcmp(str2, str1), ft_strcmp(str2, str1) == strcmp(str2, str1) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", strcmp(str1, str3), ft_strcmp(str1, str3), ft_strcmp(str1, str3) == strcmp(str1, str3) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", strcmp(str3, str1), ft_strcmp(str3, str1), ft_strcmp(str3, str1) == strcmp(str3, str1) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", strcmp(str2, str3), ft_strcmp(str2, str3), ft_strcmp(str2, str3) == strcmp(str2, str3) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", strcmp(str3, str2), ft_strcmp(str3, str2), ft_strcmp(str3, str2) == strcmp(str3, str2) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", strcmp(str1, str4), ft_strcmp(str1, str4), ft_strcmp(str1, str4) == strcmp(str1, str4) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", strcmp(str4, str1), ft_strcmp(str4, str1), ft_strcmp(str4, str1) == strcmp(str4, str1) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", strcmp(str3, str4), ft_strcmp(str3, str4), ft_strcmp(str3, str4) == strcmp(str3, str4) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", strcmp(str4, str3), ft_strcmp(str4, str3), ft_strcmp(str4, str3) == strcmp(str4, str3) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", strcmp(str5, str4), ft_strcmp(str5, str4), ft_strcmp(str5, str4) == strcmp(str5, str4) ? "yes!" : "no :(");
}
