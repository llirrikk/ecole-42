/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:32 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/05 23:08:05 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c);
int	ft_isdigit(char c);

int	ft_isalnum(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
