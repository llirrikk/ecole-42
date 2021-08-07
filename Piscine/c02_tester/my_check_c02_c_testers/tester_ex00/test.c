/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:28:23 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/06 19:28:25 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	*str1;
	char	str2[80];

	str1 = "testing...012345...проверка\n";
	ft_strcpy(str2, str1);
	printf("%s\n", str1);
	printf("%s\n", str2);
}
