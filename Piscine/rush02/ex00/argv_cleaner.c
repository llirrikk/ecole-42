/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:01:44 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/22 16:06:59 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_digit(char c);
int	is_printable(char c);

char	*argv_cleaner(char *dirty)
{
	char	*clean;
	int		clean_len;
	int		i;

	clean_len = 0;
	while (!(dirty[clean_len] == '\0' || !is_digit(dirty[clean_len])))
		clean_len++;
	clean = malloc(sizeof(clean_len) + 1);
	i = 0;
	while (i < clean_len)
	{
		clean[i] = dirty[i];
		i++;
	}
	clean[i] = '\0';
	return (clean);
}