/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:20:31 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/18 23:22:04 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

static void	fill_res_in_strjoin(char *res, char *s1, char *s2)
{
	size_t	k;

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
}

char	*ft_strjoin(char *s1, char *s2, char **free_s1)
{
	char	*res;
	size_t	total_len;
	int		is_s1_null;

	is_s1_null = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
		is_s1_null = 1;
	}
	if (s1 == NULL || s2 == NULL)
		return ((char *) NULL);
	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	res = (char *)malloc(sizeof(char) * total_len);
	if (!res)
		return ((char *) NULL);
	fill_res_in_strjoin(res, s1, s2);
	free(*free_s1);
	if (is_s1_null)
		free(s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	letter;
	char	*str;

	if (!s)
		return ((char *) NULL);
	i = 0;
	letter = (char) c;
	str = (char *) s;
	while (str[i])
	{
		if (str[i] == letter)
			return (str + i);
		i++;
	}
	if (str[i] == '\0' && letter == '\0')
		return (str + i);
	return ((char *) NULL);
}

size_t	strlen_to_first_endl(char *str)
{
	size_t	len;

	len = 0;
	while (*str && *str != '\n')
	{
		len++;
		str++;
	}
	return (len);
}
