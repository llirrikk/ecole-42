/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:38:54 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/08 18:39:10 by sserwyn          ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size - dest_len - 1 <= 0)
		return (size + dest_len);
	while (i < size - dest_len - 1 && *(src + i) != '\0')
	{
		*(dest + dest_len + i) = *(src + i);
		i++;
	}
	*(dest + dest_len + i) = '\0';
	return (src_len + dest_len);
}
