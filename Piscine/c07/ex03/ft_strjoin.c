/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:49:45 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/12 17:49:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		q;
	char	*result;

	if (size == 0)
	{
		result = "";
		return (result);
	}
	i = 0;
	q = 0;
	result = (char *)malloc(sizeof(*sep) * (size + ft_strlen(sep)) + 1);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			result[q++] = strs[i][j++];
		j = 0;
		while (j < ft_strlen(sep) && i != size - 1)
			result[q++] = sep[j++];
		i++;
	}
	result[q] = '\0';
	return (result);
}
