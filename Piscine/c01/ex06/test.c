/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:10:22 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/05 16:11:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	int	first_str;
	int second_str;

	first_str = ft_strlen("checking...");
	second_str = ft_strlen("proverka");

	printf("\"checking...\" : len = %d\n", first_str);
	printf("\"proverka\" : len = %d\n", second_str);
}
