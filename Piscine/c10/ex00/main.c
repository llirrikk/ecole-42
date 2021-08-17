/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:44:40 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/17 11:22:02 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);

#define ERROR_EXIT_CODE 1

int	display_file(int fd)
{
	int		ret;
	char	ch;

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
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (ERROR_EXIT_CODE);
	}
	else if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (ERROR_EXIT_CODE);
	}
	fd = open(argv[1], O_RDONLY);
	if (display_file(fd) == ERROR_EXIT_CODE)
	{
		ft_putstr("Cannot read file.\n");
		return (ERROR_EXIT_CODE);
	}
	close(fd);
	return (0);
}
