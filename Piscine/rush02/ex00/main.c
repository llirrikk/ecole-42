/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:29:18 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/22 16:21:50 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // <------------------------------------------------

#define DEFAULT_DICT "numbers.dict"
#define TRUE 1
#define FALSE 0

typedef struct s_numbers
{
	char				*digit;
	char				*text;
	struct s_numbers	*next;
}	t_numbers;

void		ft_putstr(char *str);
void		ft_putchar(char c);
char		*argv_cleaner(char *dirty);
t_numbers	*parsing(char *file_name);

void		number_finder(t_numbers *dict, char *digit);

int	main(int argc, char **argv)
{
	char		*clear_number;
	t_numbers	*dict;

	dict = NULL;
	clear_number = NULL;
	if (argc == 2)
	{
		clear_number = argv_cleaner(argv[1]);
		dict = parsing(DEFAULT_DICT);
	}
	else if (argc == 3)
	{
		clear_number = argv_cleaner(argv[2]);
		dict = parsing(argv[1]);
	}
	else
		ft_putstr("Error (argc)\n");
	printf("clean = %s\n", clear_number);
	printf("dict->text = %s\n", dict->text);
	printf("dict->next->text = %s\n", dict->next->text);

	number_finder(dict, clear_number);
}
