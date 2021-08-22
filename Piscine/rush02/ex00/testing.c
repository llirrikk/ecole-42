/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:13:30 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/22 13:22:41 by sserwyn          ###   ########.fr       */
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

int main(void)
{
	int			fd;
	int			ret;
	char		ch;
	int			digit_size;
	int			text_size;
	int			is_space_started;
	int			is_double_dot_started;

	t_numbers	*dict;

	char 		*digit;
	char		*text;

	dict = NULL;
	digit = malloc(sizeof(char));
	text = malloc(sizeof(char));
	digit[0] = '\0';
	text[0] = '\0';


	is_space_started = FALSE;
	is_double_dot_started = FALSE;
	digit_size = 0;
	text_size = 0;

	fd = open("numbers.dict", O_RDONLY);
	ret = read(fd, &ch, 1);
	while (ret != 0)
	{
		if (ch == ' ' && !is_double_dot_started)
			is_space_started = TRUE;
		if (is_digit(ch) && !is_space_started && !is_double_dot_started)
		{
			digit = ft_realloc(digit, ch);
			//printf("ch = %c\tdigit = %s\n", ch, digit);
			digit_size++;
		}

		is_space_started = FALSE;
		if (ch == ' ' && is_double_dot_started)
			is_space_started = TRUE;

		if (is_printable(ch) && !is_space_started && is_double_dot_started)
		{
			text = ft_realloc(text, ch);
			//printf("ch = %c\ttext = %s\n", ch, text);
			text_size++;
		}

		if (ch == ':')
		{
			is_double_dot_started = TRUE;
			is_space_started = FALSE;
		}

		if (ch == '\n')
		{
			ft_list_push_back(&dict, digit, text);

			//printf("digit_size=%d\ttext_size=%d\n", digit_size, text_size);
			// printf("text = %s\n", dict->text);
			// printf("digit = %s\n", dict->digit);


			digit = malloc(sizeof(char));
			text = malloc(sizeof(char));
			digit[0] = '\0';
			text[0] = '\0';

			text_size = 0;
			digit_size = 0;
			is_space_started = FALSE;
			is_double_dot_started = FALSE;
		}
		ret = read(fd, &ch, 1);
	}
	close(fd);


	

}
