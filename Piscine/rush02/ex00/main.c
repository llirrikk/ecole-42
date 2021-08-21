/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:29:18 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/21 19:25:49 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	my_isspace(char c)
// {
// 	if (c == '\t' || c == '\n' || c == '\v')
// 		return (1);
// 	else if (c == '\f' || c == '\r' || c == ' ')
// 		return (1);
// 	else
// 		return (0);
// }

// int	is_digit(char c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }

// int	skip_spaces(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (*(str + i) != '\0' && my_isspace(*(str + i)))
// 		i++;
// 	return (i);
// }

// int	minus_counter(int minus_count, char *str, int i)
// {
// 	if (*(str + i) == '-')
// 		minus_count++;
// 	return (minus_count);
// }

// int	ft_atoi(char *str)
// {
// 	int	i;
// 	int	minus_count;
// 	int	res;
// 	int	digit_started;

// 	digit_started = 0;
// 	minus_count = 0;
// 	res = 0;
// 	i = skip_spaces(str);
// 	while (*(str + i) != '\0')
// 	{
// 		if ((*(str + i) == '-' || *(str + i) == '+') && !digit_started)
// 			minus_count = minus_counter(minus_count, str, i);
// 		else if (is_digit(*(str + i)))
// 		{
// 			res = res * 10 + (*(str + i) - 48);
// 			digit_started = 1;
// 		}
// 		else
// 			break ;
// 		i++;
// 	}
// 	if ((minus_count % 2) && minus_count > 0)
// 		res *= -1;
// 	return (res);
// }

#include <stdlib.h>
#include <stdio.h> // <------------------------------------------------

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define DEFAULT_DICT "numbers.dict"
#define TRUE 1
#define FALSE 0

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_list_push_back_alloc(t_numbers **begin_list, int digit_size, int text_size);

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

char	*str_cleaner(char *dirty)
{
	char	*clean;
	int		clean_len;
	int		i;

	clean_len = 0;
	while (!(dirty[clean_len] == '\0' || !is_digit(dirty[clean_len])))
		clean_len++;
	clean = malloc(sizeof(clean_len) + 1);
	i = 0;
	while (i < clean_len)
	{
		clean[i] = dirty[i];
		i++;
	}
	clean[i] = '\0';
	return (clean);
}

t_numbers	*file_alloc_dict(int fd, t_numbers **dict)
{
	int			ret;
	char		ch;
	int			digit_size;
	int			text_size;
	int			is_space_started;
	int			is_double_dot_started;

	dict = NULL;
	is_space_started = FALSE;
	is_double_dot_started = FALSE;
	digit_size = 0;
	text_size = 0;
	ret = read(fd, &ch, 1);
	while (ret != 0)
	{
		if (ch == ' ' && !is_double_dot_started)
			is_space_started = TRUE;
		if (is_digit(ch) && !is_space_started && !is_double_dot_started)
			digit_size++;


		if (ch == ':')
		{
			is_double_dot_started = TRUE;
			is_space_started = FALSE;
		}
		is_space_started = FALSE;
		if (ch == ' ' && is_double_dot_started)
			is_space_started = TRUE;

		if (is_printable(ch) && !is_space_started && is_double_dot_started)
			text_size++;


		if (ch == '\n')
		{
			ft_list_push_back_alloc(&dict, digit_size+1, text_size-1+1);
			printf("digit_size=%d\ttext_size=%d\n", digit_size+1, text_size-1+1);
			text_size = 0;
			digit_size = 0;
			is_space_started = FALSE;
			is_double_dot_started = FALSE;
		}



		ret = read(fd, &ch, 1);
	}
	return (dict);
}

t_numbers	*file_fill_dict(int fd, t_numbers **dict)
{
	int			ret;
	char		ch;
	t_numbers	*dict;
	int			digit_size;
	int			text_size;
	int			is_space_started;
	int			is_double_dot_started;
	int			i;

	i = 0;
	is_space_started = FALSE;
	is_double_dot_started = FALSE;
	digit_size = 0;
	text_size = 0;
	ret = read(fd, &ch, 1);
	while (ret != 0)
	{
		if (ch == ' ' && !is_double_dot_started)
			is_space_started = TRUE;
		if (is_digit(ch) && !is_space_started && !is_double_dot_started)
			digit_size++;


		if (ch == ':')
		{
			is_double_dot_started = TRUE;
			is_space_started = FALSE;
		}
		is_space_started = FALSE;
		if (ch == ' ' && is_double_dot_started)
			is_space_started = TRUE;

		if (is_printable(ch) && !is_space_started && is_double_dot_started)
			text_size++;


		if (ch == '\n')
		{

			//ft_list_push_back_alloc(&dict, digit_size+1, text_size-1+1);
			//printf("digit_size=%d\ttext_size=%d\n", digit_size+1, text_size-1+1);
			text_size = 0;
			digit_size = 0;
			is_space_started = FALSE;
			is_double_dot_started = FALSE;
			i++;
		}



		ret = read(fd, &ch, 1);
	}
	return (dict);
}

t_numbers	*open_file(char *file_name, **dict)
{
	int			fd;

	fd = open(file_name, O_RDONLY);
	dict = file_alloc_dict(fd, &dict);
	close(fd);
	


	fd = open(file_name, O_RDONLY);
	dict = file_fill_dict(fd, &dict);
	close(fd);


	return (dict);
}

t_numbers	*parse_dict(char *file)
{
	t_numbers	*dict;

	dict = open_file(file, &dict);
	return (dict);
}

int	main(int argc, char **argv)
{
	char		*clear_number;
	t_numbers	*dict;

	clear_number = NULL;
	if (argc == 2)
	{
		clear_number = str_cleaner(argv[1]);
		printf("clean = %s\n", clear_number);
		dict = parse_dict(DEFAULT_DICT);
	}
	else if (argc == 3)
	{
		clear_number = str_cleaner(argv[2]);
		printf("clean = %s\n", clear_number);
		dict = parse_dict(argv[1]);
	}
	else
		ft_putstr("Error (argc)\n");
}
