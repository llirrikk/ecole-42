/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_triple_is.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:10:32 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/22 20:54:01 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

t_numbers	*ft_list_find_digit(t_numbers *begin_list, char *data_ref);
char		*ft_list_find_10(t_numbers *begin_list, int digits_count);
char		*ft_itoa(int nbr);
char		*char_to_char_star(char c);
void		print_from_dict(t_numbers *dict, char *c, int is_last, int is_e);
void		ft_putstr(char *str);
void		if_triple_is_3(char *triple, t_numbers *dict, int trip_count, int i)
{
	int	d_and_e;
	int	eds[3];

	eds[0] = triple[2] - '0';
	eds[1] = triple[1] - '0';
	eds[2] = triple[0] - '0';
	if (eds[0] + eds[1] + eds[2] != 0)
	{
		if (triple[0] != '0')
		{
			print_from_dict(dict, char_to_char_star(triple[0]), trip_count - i, 0);
			print_from_dict(dict, "100", trip_count - i, 0);
		}
		d_and_e = eds[1] * 10 + eds[0];
		if (d_and_e >= 10 && d_and_e < 20)
			print_from_dict(dict, ft_itoa(d_and_e), trip_count - i, 0);
		else if (eds[1] > 1)
		{
			print_from_dict(dict, ft_itoa(eds[1] * 10), trip_count - i, 0);
			if (triple[2] != '0')
				print_from_dict(dict, char_to_char_star(triple[2]), trip_count - i, 1);
		}
		else
		{
			if (triple[1] != '0')
			{
				print_from_dict(dict, char_to_char_star(triple[1]), trip_count - i, 1);
				print_from_dict(dict, "10", trip_count - i, 0);
			}
			if (triple[2] != '0')
				print_from_dict(dict, char_to_char_star(triple[2]), trip_count - i, 1);
		}
	}
}

void	if_triple_is_2(char *triple, t_numbers *dict, int trip_count, int i)
{
	int	d_and_e;
	int	eds[3];

	eds[0] = triple[1] - '0';
	eds[1] = triple[0] - '0';
	d_and_e = eds[1] * 10 + eds[0];
	if (d_and_e >= 10 && d_and_e < 20)
		print_from_dict(dict, ft_itoa(d_and_e), trip_count - i, 0);
	else if (eds[1] > 1)
	{
		print_from_dict(dict, ft_itoa(eds[1] * 10), trip_count - i, 0);
		if (triple[1] != '0')
			print_from_dict(dict, char_to_char_star(triple[1]), trip_count - i, 1);
	}
}
