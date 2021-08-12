/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:50:00 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/12 17:50:14 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char	*strs[] = {"aboba", "abobus", "42", "work_please"};
	char	*sep = "+++";
	printf("\nres = '%s'\n", ft_strjoin(4, strs, sep));
	
	printf("\nres = '%s'\n", ft_strjoin(0, strs, sep));
}
