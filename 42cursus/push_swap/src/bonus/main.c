/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 00:25:46 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/08 03:35:20 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	read_console(t_all *all)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		use_instructions(all, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc < 2)
		return (1);
	if (!is_args_valid(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	all.argv = argv;
	all.argc = argc;
	all.a = NULL;
	all.b = NULL;
	parse_to_stack(&all);
	read_console(&all);
	if (is_stack_sorted(all.a) && find_stack_size(all.b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	handled_exit(&all);
}
