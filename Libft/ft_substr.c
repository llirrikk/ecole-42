/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:12:47 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/09 20:29:00 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return ((char *) NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return ((char *) NULL);
	if ((unsigned int)ft_strlen((char *)s) >= start)
		ft_strlcpy(res, s + start, len + 1);
	return (res);
}
