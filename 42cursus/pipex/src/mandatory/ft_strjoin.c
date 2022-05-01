/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn@student.21-school.ru <sserwyn>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:30:07 by sserwyn           #+#    #+#             */
/*   Updated: 2022/04/16 23:51:01 by sserwyn@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	total_len;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return ((char *) NULL);
	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	res = (char *)malloc(sizeof(char) * total_len);
	if (!res)
		return ((char *) NULL);
	k = 0;
	while (*s1)
	{
		res[k++] = *s1;
		s1++;
	}
	while (*s2)
	{
		res[k++] = *s2;
		s2++;
	}
	res[k] = '\0';
	return (res);
}
