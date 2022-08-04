/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ft_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:59:41 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/29 19:03:11 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen_without_last_nl(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	if (i > 0 && *(str + i - 1) == '\n')
		i--;
	return (i);
}