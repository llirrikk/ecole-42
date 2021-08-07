/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:44:36 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 15:44:55 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	*str1_1;
	char	str2_1[80];
	char	str2_1_from_good[80];

	char	*str1_2;
	char	str2_2[12];
	char	str2_2_from_good[12];

	char	*test1;
	char	test1_1[40];
	char	*test2;
	char	test2_1[51];
	char	*test3;
	char	test3_1[6];


	printf("test #1:\n");
	str1_1 = "testing...012345...проверка\n";
	ft_strlcpy(str2_1, str1_1, sizeof(str2_1));
	strlcpy(str2_1_from_good, str1_1, sizeof(str2_1_from_good));
	printf("\n%s", str2_1);
	printf("\n%s", str2_1_from_good);
	printf("\ntest #2:\n");
	str1_2 = "01234567890";
	ft_strlcpy(str2_2, str1_2, sizeof(str2_2) - 5);
	strlcpy(str2_2_from_good, str1_2, sizeof(str2_2_from_good) - 5);
	printf("\n%s", str2_2);
	printf("\n%s", str2_2_from_good);

	printf("\n\ntest #3:\n");

	test1 = "fwefiugh45lk";
	printf("\nft_strlcpy(test1_1, test1, 7) = %u\n", ft_strlcpy(test1_1, test1, 7));
	printf("strlcpy(test1_1, test1, 7) = %lu\n", strlcpy(test1_1, test1, 7));
	
	test2 = "3rouhgig";
	printf("\nft_strlcpy(test2_1, test2, sizeof(test2_1)) = %u\n", ft_strlcpy(test2_1, test2, sizeof(test2_1)));
	printf("strlcpy(test2_1, test2, sizeof(test2_1)) = %lu\n", strlcpy(test2_1, test2, sizeof(test2_1)));

	test3 = "";
	printf("\nft_strlcpy(test2_1, test2, sizeof(test3_1)) = %u\n", ft_strlcpy(test3_1, test3, sizeof(test3_1)));
	printf("strlcpy(test2_1, test2, sizeof(test3_1)) = %lu\n", strlcpy(test3_1, test3, sizeof(test3_1)));

}
