/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:17:23 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/17 12:21:50 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/errno.h>
#include <string.h>
#include <libgen.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

#define ERROR_EXIT_CODE 1

int	read_file(int fd)
{
	int		ret;
	char	ch;

	ret = read(fd, &ch, 1);
	while (ret != 0)
	{
		ft_putchar(ch);
		ret = read(fd, &ch, 1);
		if (ret == -1)
		{
			return (errno);
		}
	}
	return (0);
}

int	open_file(char *file_name)
{
	int	fd;
	int	my_errno;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		return (errno);
	}
	my_errno = read_file(fd);
	if (my_errno != 0)
		return (my_errno);
	if (close(fd) == -1)
		return (errno);
	return (0);
}

void	scan_console(void)
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

int	parse_argv(int argc, char **argv)
{
	int	i;
	int	my_errno;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && ft_strlen(argv[i]) == 1)
			scan_console();
		else
		{
			my_errno = open_file(argv[i]);
			if (my_errno != 0)
			{
				ft_putstr(basename(argv[0]));
				ft_putstr(": ");
				ft_putstr(argv[i]);
				ft_putstr(": ");
				ft_putstr(strerror(my_errno));
				ft_putchar('\n');
				return (my_errno);
			}
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	my_errno;

	if (argc == 0)
	{
		ft_putstr("Error!\n");
		return (ERROR_EXIT_CODE);
	}
	if (argc == 1)
		scan_console();
	else
	{
		my_errno = parse_argv(argc, argv);
		if (my_errno != 0)
			return (my_errno);
	}
	return (0);
}
