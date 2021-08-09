/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:53:28 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/09 13:53:44 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <stdlib.h>

int	ft_atoi(char *str);

int	main(void)
{
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("-0"));
	printf("%d\n", ft_atoi("-1"));
	printf("%d\n", ft_atoi("1"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("---------2147483648"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("       \r--2147483647"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("     --+++-+-3---+--228"));
	printf("%d\n", ft_atoi("  6   --+++-+-3---+--228"));
	printf("%d\n", ft_atoi("--+++-+-3\t-+--228"));
	printf("%d\n", ft_atoi("--+++-+-3++++++228"));
	printf("%d\n", ft_atoi("--+++-+-3---+--228"));
	printf("%d\n", ft_atoi("--+++-+-3 -+--228"));
	printf("%d\n", ft_atoi("--+++-+----+--228"));
	printf("%d\n", ft_atoi("--+++-+----+--228t"));
	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
	printf("%d\n", ft_atoi("\t\n\v\f\r 987654"));
	printf("%d\n", ft_atoi("\t\n\v\f\r ---987654"));
	printf("%d\n", ft_atoi("\t\n\v\f\r --+987654"));
}
