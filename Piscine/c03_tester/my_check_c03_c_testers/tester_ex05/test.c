/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:39:17 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/08 18:39:31 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char app[1024] = "вторая строка ";
	char dst[1024] = "первая строка";

	printf("%s\n", ft_strlcat(dst, app, 6) == strlcat(dst, app, 6) ? "OK!" : "KO:(");
	printf("%d, %lu\n", ft_strlcat(dst, app, 6), strlcat(dst, app, 6));

	// char s1[1024] = "@IU^FRB&^@IUYG$\n\\#NF U#$ ";
	// char s2[1024] = "FMOG*GM#U\t#hifulf";
	// char s1_1[1024] = "@IU^FRB&^@IUYG$\n\\#NF U#$ ";
	// char s2_1[1024] = "FMOG*GM#U\t#hifulf";

	char s3[1024] = "@ewverkjbnvjke ";
	char s4[1024] = "";

	printf("%s\n", (ft_strlcat(s4, s3, strlen(s4)) == strlcat(s4, s3, strlen(s4))) ? "OK!" : "KO:(");
	printf("%d, %lu\n", ft_strlcat(s4, s3, strlen(s4)), strlcat(s4, s3, strlen(s4)));
}
