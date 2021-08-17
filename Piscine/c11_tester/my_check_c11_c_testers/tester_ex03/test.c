/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:12:15 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/17 15:18:33 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (*(str + i) != '\0')
	{
		if (!(*(str + i) >= '0' && *(str + i) <= '9'))
		{
			res = 0;
			break ;
		}
		i++;
	}
	return (res);
}

int	ft_count_if(char **tab, int length, int(*f)(char*));

int main(void)
{
	char *tab1[] = {"82385", "32239857892397532"};
	char *tab2[] = {"FFJEI", "oeihg"};
	char *tab3[] = {"FFJEI", "JKBV#JKRLNLVJW"};
	char *tab4[] = {"52353262362332", "62362353253245", "283742374689230432852350", "52385923590839025235", "jbfu3g73n"};
	printf("res1 = %d\n", ft_count_if(tab1, 2, &ft_str_is_numeric));
	printf("res2 = %d\n", ft_count_if(tab2, 2, &ft_str_is_numeric));
	printf("res3 = %d\n", ft_count_if(tab3, 2, &ft_str_is_numeric));
	printf("res4 = %d\n", ft_count_if(tab4, 5, &ft_str_is_numeric));
}
