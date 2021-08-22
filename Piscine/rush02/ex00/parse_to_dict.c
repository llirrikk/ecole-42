/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:55:48 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/22 15:57:39 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_digit(char c);
int	is_printable(char c);
char	*ft_realloc(char *old, char ch);

#define TRUE 1
#define FALSE 0

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

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