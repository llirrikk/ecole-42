/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 16:41:52 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/08 16:42:05 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char app[1024] = "вторая строка ";
	char dst[1024] = "первая строка";

	ft_strcat(dst, app);
	printf("%s\n", strcmp(ft_strcat(dst, app), strcat(dst, app)) == 0 ? "OK!" : "KO:(");

	char s1[1024] = "@IU^FRB&^@IUYG$\n\\#NF U#$ ";
	char s2[1024] = "FMOG*GM#U\t#hifulf";
	char s1_1[1024] = "@IU^FRB&^@IUYG$\n\\#NF U#$ ";
	char s2_1[1024] = "FMOG*GM#U\t#hifulf";

	char s3[1024] = "@ewverkjbnvjke ";
	char s4[1024] = "";

	ft_strcat(s1, s2);
	strcat(s1_1, s2_1);

	printf("%s\n", strcmp(s1, s1_1) == 0 ? "OK!" : "KO:(");
	printf("%s\n", strcmp(ft_strcat(s4, s3), strcat(s4, s3)) == 0 ? "OK!" : "KO:(");
}
