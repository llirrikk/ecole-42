/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:37:35 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/09 11:37:52 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	printf("%s\n", (strlen("aboba") == ft_strlen("aboba") ? "OK!" : "KO :("));
	printf("%s\n", (strlen("aboba\t") == ft_strlen("aboba\t") ? "OK!" : "KO :("));
	printf("%s\n", (strlen("") == ft_strlen("") ? "OK!" : "KO :("));
	printf("%s\n", (strlen("\n") == ft_strlen("\n") ? "OK!" : "KO :("));
	printf("%s\n", (strlen("I*N&TF$I#GuYFGNG34f67 8g3fo78g#In#8") == ft_strlen("I*N&TF$I#GuYFGNG34f67 8g3fo78g#In#8") ? "OK!" : "KO :("));
}
