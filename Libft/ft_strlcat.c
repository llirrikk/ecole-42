/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:21 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/06 23:16:19 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen((char *)src);
	if ((size_t)ft_strlen(dst) < size)
		len += (size_t)ft_strlen(dst);
	else
		len += size;
	if (size == 0)
		return (len);
	i = 0;
	while (dst[i])
		i++;
	while (src[j] && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len);
}
