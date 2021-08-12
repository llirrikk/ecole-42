/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:01:48 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/12 11:02:01 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strdup(char *src);

int	main(void)
{
	printf("'%s' == '%s'?\n", "abbbbbbbbbobba", ft_strdup("abbbbbbbbbobba"));
	printf("'%s' == '%s'?\n", "KJHBFuoyg2oyg287", ft_strdup("KJHBFuoyg2oyg287"));
	printf("'%s' == '%s'?\n", "IOUY@NTFOH C@UIYGHC@#", ft_strdup("IOUY@NTFOH C@UIYGHC@#"));
	printf("'%s' == '%s'?\n", "ui23ytro23867r9n3278ny238", ft_strdup("ui23ytro23867r9n3278ny238"));
}
