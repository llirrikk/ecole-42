/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:49:44 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 13:50:02 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;
	int	t;

	i = 0;
	while (*(str + i) != '\0')
	{
		t = *(str + i);
		if (t >= 'A' && t <= 'Z')
			*(str + i) += 32;
		i++;
	}
	return (str);
}