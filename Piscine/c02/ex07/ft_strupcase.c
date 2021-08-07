/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:19:00 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 13:19:15 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;
	int	t;

	i = 0;
	while (*(str + i) != '\0')
	{
		t = *(str + i);
		if (t >= 'a' && t <= 'z')
			*(str + i) -= 32;
		i++;
	}
	return (str);
}