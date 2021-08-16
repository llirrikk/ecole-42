/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:17:23 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/16 18:26:51 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/errno.h>
#include <string.h>
// #include <stdio.h> ??


void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

#define ERROR_EXIT_CODE 1

int	display_file(char *file_name)
{
	int		ret;
	char	ch;
	int		fd;

	fd = open(file_name, O_RDONLY);
	ret = read(fd, &ch, 1);
	if (fd < 0 || ret == -1)
	{
		return (ERROR_EXIT_CODE);
	}
	while (ret != 0)
	{
		ft_putchar(ch);
		ret = read(fd, &ch, 1);
		if (ret == -1)
			return (ERROR_EXIT_CODE);
	}
	close(fd);
	return (0);
}

void	scan_console()
{
	int		ret;
	char	ch;

	ret = read(1, &ch, 1);
	while (ret != 0)
	{
		ft_putchar(ch);
		ret = read(1, &ch, 1);
	}
}

// ???
int	is_argv_equal_mm(char *argv, int i)
{
	if (i == 1)
		return (argv[0] == '-' && argv[1] == '-' && ft_strlen(argv) == 2);
	else
		return (0);
}
// ???

void	parse_argv(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && ft_strlen(argv[i]) == 1)
			scan_console();
		
		// ???
		else if (is_argv_equal_mm(argv[i], i))
			scan_console();
		// ???
		
		else
		{
			display_file(argv[i]);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 0)
	{
		//ft_putstr(strerror(errno)); //?
		ft_putstr("Error!\n");
		return (ERROR_EXIT_CODE);
	}
	if (argc == 1)
		scan_console();
	else
		parse_argv(argc, argv);
	return (0);
}