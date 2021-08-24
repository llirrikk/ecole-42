/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_console_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:18:13 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/24 13:34:59 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_realloc(char *old, char ch);
int		number_1st_line(char *line);
void	str_init(char **str);

void	read_console(char *file_name)
{
	char	ch;
	int		fd;
	int		line_count;
	//int		user_height;
	char	*header;

	str_init(&header);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC);
	// if (fd == -1)
	// 	map_error_exit();

	//user_height = 2147483647;
	line_count = 0;
	while (read(1, &ch, 1) != 0)
	{
		if (line_count == 0)
			header = ft_realloc(header, ch);
		if (ch == '\n')
		{
			line_count++;
			if (line_count == 1)
			{
				//user_height = number_1st_line(header);
				free(header);
			}
		}
		write(fd, &ch, 1);
	}
	close(fd);
}
