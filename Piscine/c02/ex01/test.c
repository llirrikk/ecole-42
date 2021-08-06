/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 20:39:26 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/06 20:39:36 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	*str1_1;
	char	str2_1[80];
	char	*str1_2;
	char	str2_2[12];

	printf("test #1:\n");
	str1_1 = "testing...012345...проверка\n";
	ft_strncpy(str2_1, str1_1, sizeof(str2_1));
	printf("%s", str1_1);
	printf("\n%s", str2_1);
	printf("\ntest #2:\n");
	str1_2 = "01234567890";
	ft_strncpy(str2_2, str1_2, sizeof(str2_2) + 5);
	printf("%s", str1_2);
	printf("\n%s", str2_2);
}
