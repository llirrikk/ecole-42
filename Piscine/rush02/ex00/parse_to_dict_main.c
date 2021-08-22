/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_dict_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:03:14 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/22 16:14:13 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

void	init_digit_text(char **digit, char **text);
void	init_is_space_dd(int *a, int *b, int is_space, int is_dd);
void	init_dict_is_a_b(t_numbers **dict, int *a, int *b);
void	digits_in_loop(char ch, int *is_space, int is_dd, char **digit);
void	texts_in_loop(char ch, int *is_space, int *is_dd, char **text);
void	ft_list_push_back(t_numbers **begin_list, char *digit, char *text);

// nor[0] = int			fd;
// nor[1] = int			ret;
// nor[2] = int			is_space_started;
// nor[3] = int			is_double_dot_started;
t_numbers	*parsing(char *file_name)
{
	int			nor[4];
	char		ch;
	t_numbers	*dict;
	char		*digit;
	char		*text;

	init_digit_text(&digit, &text);
	init_dict_is_a_b(&dict, &nor[2], &nor[3]);
	nor[0] = open(file_name, O_RDONLY);
	nor[1] = read(nor[0], &ch, 1);
	while (nor[1] != 0)
	{
		digits_in_loop(ch, &nor[2], nor[3], &digit);
		texts_in_loop(ch, &nor[2], &nor[3], &text);
		if (ch == '\n')
		{
			ft_list_push_back(&dict, digit, text);
			init_digit_text(&digit, &text);
			init_is_space_dd(&nor[2], &nor[3], 0, 0);
		}
		nor[1] = read(nor[0], &ch, 1);
	}
	close(nor[0]);
	return (dict);
}
