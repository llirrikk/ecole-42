/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:48:29 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/18 19:35:42 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_string_tab(char **tab);

int main(void)
{
	char	*tab[] = {"iugh93jg", "aiugfwgweg0brw", "zh8hgr3", (void *)0};

	for (int i = 0; i < 4; i++)
		printf("%s\n", tab[i]);

	printf("--------\n");

	ft_sort_string_tab(tab);

	for (int i = 0; i < 3; i++)
		printf("%s\n", tab[i]);
}