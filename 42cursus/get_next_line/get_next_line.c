/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:36:36 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/17 21:49:44 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_stream(int fd)
{
	char	*line;
	char	*buff;
	int		ret;

	// line = (char *)malloc(sizeof(char));
	// line[0] = '\0';
	line = NULL;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			// free(line);??
			return ((char *) NULL);
		}
		if (ret == 0)
			break ;
		buff[ret] = '\0';
		// printf("buff = '%s'\n", buff);
		line = ft_strjoin(line, buff);
		// printf("line = '%s'\n\n", line);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(buff);
	return (line);
}

size_t	strlen_to_first_endl(char *str)
{
	size_t	len;

	len = 0;
	while (*str && *str != '\n')
	{
		len++;
		str++;
	}
	return (len);
}

char	*remove_extra_chars(char *dirty_line)
{
	char	*clean_line;
	size_t	clean_size;
	size_t	i;

	clean_size = strlen_to_first_endl(dirty_line);
	i = 0;
	clean_line = (char *)malloc(sizeof(char) * (clean_size + 2));
	while (i < clean_size)
	{
		clean_line[i] = dirty_line[i];
		i++;
	}
	if (dirty_line[i] == '\n')
		clean_line[i++] = '\n';
	clean_line[i] = '\0';
	free(dirty_line);
	return (clean_line);
}

char	*get_next_line(int fd)
{
	char	*dirty_line;
	char	*clean_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((char *) NULL);
	dirty_line = get_stream(fd);
	// printf("dirty_line = '%s'\n", dirty_line);
	if (dirty_line == NULL)
		return ((char *) NULL);
	clean_line = remove_extra_chars(dirty_line);
	// printf("clean_line = '%s'\n", clean_line);
	// getchar();
	return (clean_line);
}
