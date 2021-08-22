/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:17:42 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/22 20:57:13 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // <------------------------------------------------
#include <stdlib.h>

void	ft_putstr(char *str);

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

int			ft_strlen(char *str);
t_numbers	*ft_list_find_digit(t_numbers *begin_list, char *data_ref);
char		*ft_list_find_10(t_numbers *begin_list, int digits_count);
char		*ft_itoa(int nbr);
int			ft_recursive_power(int nb, int power);
void		if_triple_is_3(char *triple, t_numbers *dict, int trip_count, int i);
void		if_triple_is_2(char *triple, t_numbers *dict, int trip_count, int i);

char	*char_to_char_star(char c)
{
	char	*pChar;

	pChar = malloc(sizeof(char));
	*pChar = c;
	return (pChar);
}

void	print_from_dict(t_numbers *dict, char *c, int is_last, int is_e)
{
	dict = ft_list_find_digit(dict, c);
	ft_putstr(dict->text);
	if (is_last > 0 && !is_e)
		ft_putstr(" ");
}


void	triple_init(char *a, char *b, char *c, char *d)
{
	*a = '\0';
	*b = '\0';
	*c = '\0';
	*d = '\0';
}

void number_finder(t_numbers *dict, char *digits)
{
	int			i;
	int			j;
	int			q;
	int			trip_count;
	int			used;
	char		triple[4];

	q = 0;
	trip_count = ft_strlen(digits) / 3;
	if (ft_strlen(digits) % 3 != 0)
		trip_count++;

	triple_init(&triple[0], &triple[1], &triple[2], &triple[3]);
	used = 0;
	i = 0;
	while (i < trip_count)
	{
		j = 0;
		if ((ft_strlen(digits) - used) % 3 == 0)
		{
			while (j < 3)
			{
				triple[j] = digits[q];
				q++;
				used++;
				j++;
			}
		}
		else
		{
			while (j < (ft_strlen(digits) % 3))
			{
				used++;
				triple[j] = digits[q];
				q++;
				j++;
			}
			
		}
		triple[j] = '\0';

		//------//

		if (ft_strlen(triple) == 3)
			if_triple_is_3(triple, dict, trip_count, i);
		else if (ft_strlen(triple) == 2)
			if_triple_is_2(triple, dict, trip_count, i);
		else if (ft_strlen(triple) == 1)
		{
			print_from_dict(dict, char_to_char_star(triple[0]), trip_count - i, 1);
		}
		if (trip_count - i > 1 && !(triple[0] == '0' && triple[1] == '0' && triple[2] == '0'))
		{
			ft_putstr(" ");
			ft_putstr(ft_list_find_10(dict, ft_strlen(digits) - used + 1));
		}
		if (trip_count - i - 1 != 0)
			ft_putstr(" ");


		//------// 123
		triple_init(&triple[0], &triple[1], &triple[2], &triple[3]);
		i++;
	}

	


	ft_putstr("\n");
	
}
