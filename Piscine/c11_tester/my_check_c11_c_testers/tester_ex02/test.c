/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:53:34 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/17 15:07:05 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int ft_any(char **tab, int(*f)(char*));

int main(void)
{
	char *tab1[] = {"wergewgwrherhwer", "oeihg", (void *)0};
	char *tab2[] = {"FFJEI", "oeihg", (void *)0};
	char *tab3[] = {"FFJEI", "JKBV#JKRLNLVJW", (void *)0};
	char *tab4[] = {"52353262362332", "62362353253245", (void *)0};
	printf("res1 = %d\n", ft_any(tab1, &ft_str_is_uppercase));
	printf("res2 = %d\n", ft_any(tab2, &ft_str_is_uppercase));
	printf("res3 = %d\n", ft_any(tab3, &ft_str_is_uppercase));
	printf("res4 = %d\n", ft_any(tab4, &ft_str_is_uppercase));
}
