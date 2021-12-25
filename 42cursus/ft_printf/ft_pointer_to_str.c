/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:35:54 by sserwyn           #+#    #+#             */
/*   Updated: 2021/11/24 13:59:09 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src);

size_t	count_16_in_nbr(unsigned long p)
{
	size_t	c;

	c = 0;
	while (p != 0)
	{
		p /= 16;
		c++;
	}
	return (c);
}

char	*pointer_to_str(unsigned long p)
{
	char	*str;
	size_t	count_16_in_p;

	if (!p)
	{
		str = (char *)malloc(sizeof(char) * 3);
		ft_strcpy(str, "0x0");
		return (str);
	}
	count_16_in_p = count_16_in_nbr((unsigned long)p);
	str = (char *)malloc(sizeof(char) * (count_16_in_p + 2 + 1));
	str[0] = '0';
	str[1] = 'x';
	str[count_16_in_p + 3 - 1] = '\0';
	count_16_in_p += 2 - 1;
	while (count_16_in_p > 1)
	{
		if (p % 16 >= 10 && p % 16 <= 15)
			str[count_16_in_p] = p % 16 % 10 + 'a';
		else
			str[count_16_in_p] = p % 16 + '0';
		count_16_in_p--;
		p /= 16;
	}
	return (str);
}
