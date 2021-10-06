/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:22:42 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/06 23:15:53 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (nmemb == 0 || size == 0)
		return ((void *) NULL);
	ptr = (char *)malloc(nmemb * size);
	if (!ptr)
		return ((void *) NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
