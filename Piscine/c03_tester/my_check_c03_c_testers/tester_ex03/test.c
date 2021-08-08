/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:01:31 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/08 17:01:45 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char app[1024] = "вторая строка ";
	char dst[1024] = "первая строка";

	ft_strncat(dst, app, 5);
	printf("%s\n", strcmp(ft_strncat(dst, app, 6), strncat(dst, app, 6)) == 0 ? "OK!" : "KO:(");

	char s1[1024] = "@IU^FRB&^@IUYG$\n\\#NF U#$ ";
	char s2[1024] = "FMOG*GM#U\t#hifulf";
	char s1_1[1024] = "@IU^FRB&^@IUYG$\n\\#NF U#$ ";
	char s2_1[1024] = "FMOG*GM#U\t#hifulf";

	char s3[1024] = "@ewverkjbnvjke ";
	char s4[1024] = "";

	ft_strncat(s1, s2, strlen(s1));
	strncat(s1_1, s2_1, strlen(s1_1));

	printf("%s\n", strcmp(s1, s1_1) == 0 ? "OK!" : "KO:(");
	printf("%s\n", strcmp(ft_strncat(s4, s3, strlen(s4)), strncat(s4, s3, strlen(s4))) == 0 ? "OK!" : "KO:(");
}
