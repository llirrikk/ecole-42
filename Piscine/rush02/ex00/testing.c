/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:13:30 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/22 14:34:28 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // <------------------------------------------------

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (TRUE);
	return (FALSE);
}

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

char	*ft_realloc(char *old, char ch);
void	ft_list_push_back(t_numbers **begin_list, char *digit, char *text);

void	init_digit_text(char **digit, char **text)
{
	*digit = malloc(sizeof(char));
	*text = malloc(sizeof(char));
	*digit[0] = '\0';
	*text[0] = '\0';
}

void	init_is_space_dd(int *a, int *b, int is_space, int is_dd)
{
	*a = is_space;
	*b = is_dd;
}

void	init_dict_is_a_b(t_numbers **dict, int *a, int *b)
{
	*dict = NULL;
	*a = FALSE;
	*b = FALSE;
}

void	digits_in_loop(char ch, int *is_space, int is_dd, char **digit)
{
	if (ch == ' ' && !is_dd)
		*is_space = TRUE;
	if (is_digit(ch) && !(*is_space) && !is_dd)
		*digit = ft_realloc(*digit, ch);
	*is_space = FALSE;
}

void	texts_in_loop(char ch, int *is_space, int *is_dd, char **text)
{
	if (ch == ' ' && *is_dd)
		*is_space = TRUE;
	if (is_printable(ch) && !(*is_space) && *is_dd)
		*text = ft_realloc(*text, ch);
	if (ch == ':')
		init_is_space_dd(is_space, is_dd, 0, 1);
}

// nor[0] = int			fd;
// nor[1] = int			ret;
// nor[2] = int			is_space_started;
// nor[3] = int			is_double_dot_started;
int	main(void)
{
	int			nor[4];
	char		ch;
	t_numbers	*dict;
	char		*digit;
	char		*text;

	init_digit_text(&digit, &text);
	init_dict_is_a_b(&dict, &nor[2], &nor[3]);
	nor[0] = open("numbers.dict", O_RDONLY);
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
}
