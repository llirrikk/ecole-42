/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:26:22 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/08 17:26:34 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*norminette_is_shit(int j, char *first_c, char *src)
{
	if (j == 0)
		first_c = src;
	return (first_c);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		to_find_len;
	char	*first_c;

	if (*to_find == '\0')
		return (str);
	to_find_len = ft_strlen(to_find);
	i = 0;
	j = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == *(to_find + j))
		{
			first_c = norminette_is_shit(j, first_c, str + i);
			if (*(to_find + j) != '\0')
				if (j == to_find_len - 1)
					return (first_c);
			j++;
		}
		else
			j = 0;
		i++;
	}
	return (0);
}
