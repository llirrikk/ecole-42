/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:26:40 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/08 17:26:55 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	s1[] = "abcdefg";
	char	s2[] = "h";
	printf("%s\n", ft_strstr(s1, s2) == NULL ? "it's NULL" : ft_strstr(s1, s2));
	printf("%s\n", ft_strstr("abcdefg", "abcdefg") == NULL ? "it's NULL" : ft_strstr("abcdefg", "abcdefg"));
	printf("%s\n", ft_strstr("abcdefg", "fg") == NULL ? "it's NULL" : ft_strstr("abcdefg", "fg"));
	printf("%s\n", ft_strstr("fg", "f") == NULL ? "it's NULL" : ft_strstr("fg", "f"));
	printf("%s\n", ft_strstr("HIUOF", "") == NULL ? "it's NULL" : ft_strstr("HIUOF", ""));
	printf("%s\n", ft_strstr("", "fwe") == NULL ? "it's NULL" : ft_strstr("", "fwe"));
	printf("%s\n", ft_strstr("abcdefg", "ab") == NULL ? "it's NULL" : ft_strstr("abcdefg", "ab"));
}
