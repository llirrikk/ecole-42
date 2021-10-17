/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sserwyn <sserwyn@student.21-school.ru>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/16 18:35:47 by sserwyn		   #+#	#+#			 */
/*   Updated: 2021/10/17 01:55:35 by sserwyn		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_realloc(char *left, char *right)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * (ft_strlen(left) + (ft_strlen(right))));
	i = 0;
	while (i < ft_strlen(left))
	{
		new[i] = left[i];
		i++;
	}
	while (i < ft_strlen(right))
	{
		new[i] = right[i];
		i++;
	}
	new[i] = '\0';
	free(left);
	free(right);
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	total_len;
	size_t	k;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return ((char *) NULL);
	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	// res = ft_realloc(s1, s2);
	// return (res);
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
	// free(s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	letter;
	char	*str;

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
