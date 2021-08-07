/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:47:53 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 12:48:06 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	res;
	int	t;

	res = 1;
	i = 0;
	while (*(str + i) != '\0')
	{
		t = *(str + i);
		if (!(t >= 'A' && t <= 'Z'))
		{
			res = 0;
			break ;
		}
		i++;
	}
	return (res);
}