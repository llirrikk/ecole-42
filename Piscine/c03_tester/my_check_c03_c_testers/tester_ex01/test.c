/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 16:19:35 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/08 16:19:50 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char	str1[] = "inviep-g5";
	char	str2[] = "inviep-05";
	char	str3[] = "inviep";
	char	str4[] = "tr";
	char	str5[] = "";

	printf("is (%d == %d)? : %s\n", ft_strncmp(str1, str1, sizeof(str1)), ft_strncmp(str1, str1, sizeof(str1)), ft_strncmp(str1, str1, sizeof(str1)) == ft_strncmp(str1, str1, sizeof(str1)) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", ft_strncmp(str1, str2, sizeof(str1)), ft_strncmp(str1, str2, sizeof(str1)), ft_strncmp(str1, str2, sizeof(str1)) == ft_strncmp(str1, str2, sizeof(str1)) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", ft_strncmp(str2, str1, sizeof(str2)), ft_strncmp(str2, str1, sizeof(str2)), ft_strncmp(str2, str1, sizeof(str2)) == ft_strncmp(str2, str1, sizeof(str2)) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", ft_strncmp(str1, str3, 4), ft_strncmp(str1, str3, 4), ft_strncmp(str1, str3, 4) == ft_strncmp(str1, str3, 4) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", ft_strncmp(str3, str1, sizeof(str3)), ft_strncmp(str3, str1, sizeof(str3)), ft_strncmp(str3, str1, sizeof(str3)) == ft_strncmp(str3, str1, sizeof(str3)) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", ft_strncmp(str2, str3, 100), ft_strncmp(str2, str3, 100), ft_strncmp(str2, str3, 100) == ft_strncmp(str2, str3, 100) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", ft_strncmp(str3, str2, sizeof(str3)), ft_strncmp(str3, str2, sizeof(str3)), ft_strncmp(str3, str2, sizeof(str3)) == ft_strncmp(str3, str2, sizeof(str3)) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", ft_strncmp(str1, str4, sizeof(str1)), ft_strncmp(str1, str4, sizeof(str1)), ft_strncmp(str1, str4, sizeof(str1)) == ft_strncmp(str1, str4, sizeof(str1)) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", ft_strncmp(str4, str1, sizeof(str4)), ft_strncmp(str4, str1, sizeof(str4)), ft_strncmp(str4, str1, sizeof(str4)) == ft_strncmp(str4, str1, sizeof(str4)) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", ft_strncmp(str3, str4, 1), ft_strncmp(str3, str4, 1), ft_strncmp(str3, str4, 1) == ft_strncmp(str3, str4, 1) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", ft_strncmp(str4, str3, sizeof(str4)), ft_strncmp(str4, str3, sizeof(str4)), ft_strncmp(str4, str3, sizeof(str4)) == ft_strncmp(str4, str3, sizeof(str4)) ? "yes!" : "no :(");
	printf("is (%d == %d)? : %s\n", ft_strncmp(str5, str4, sizeof(str5)), ft_strncmp(str5, str4, sizeof(str5)), ft_strncmp(str5, str4, sizeof(str5)) == ft_strncmp(str5, str4, sizeof(str5)) ? "yes!" : "no :(");
}
