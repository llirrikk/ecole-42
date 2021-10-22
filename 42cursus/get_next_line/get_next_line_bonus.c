/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:08:54 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/18 23:25:00 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_stream(int fd, char *full_line)
{
	char			*buff;
	long long int	ret;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return ((char *) NULL);
	ret = 1;
	while (!ft_strchr(full_line, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return ((char *) NULL);
		}
		if (ret == 0)
			break ;
		buff[ret] = '\0';
		full_line = ft_strjoin(full_line, buff, &full_line);
	}
	free(buff);
	return (full_line);
}

char	*remove_right_side(char *str)
{
	char	*only_left_side;
	size_t	clean_size;
	size_t	i;

	clean_size = strlen_to_first_endl(str);
	i = 0;
	only_left_side = (char *)malloc(sizeof(char) * (clean_size + 2));
	while (i < clean_size)
	{
		only_left_side[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		only_left_side[i++] = '\n';
	if (i != 0)
		only_left_side[i] = '\0';
	else
	{
		free(only_left_side);
		return ((char *) NULL);
	}
	return (only_left_side);
}

static void	fill_o_r_s(char *only_right_side, int i, int str_len, char *str)
{
	int	k;

	k = 0;
	while (i < str_len)
	{
		only_right_side[k++] = str[i];
		i++;
	}
	only_right_side[k] = '\0';
}

char	*remove_left_side(char *str)
{
	int		str_len;
	int		i;
	char	*only_right_side;

	str_len = ft_strlen(str);
	i = strlen_to_first_endl(str);
	if (str_len - i == 0)
	{
		free(str);
		return ((char *) NULL);
	}
	only_right_side = (char *)malloc(sizeof(char) * (str_len - i));
	if (!only_right_side)
		return ((char *) NULL);
	if (str[i] == '\n')
		i++;
	fill_o_r_s(only_right_side, i, str_len, str);
	free(str);
	return (only_right_side);
}

char	*get_next_line(int fd)
{
	static char	*full_line[FD_MAX_COUNT] = {0};
	char		*left_side_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((char *) NULL);
	full_line[fd] = get_stream(fd, full_line[fd]);
	if (!full_line[fd])
		return ((char *) NULL);
	left_side_line = remove_right_side(full_line[fd]);
	full_line[fd] = remove_left_side(full_line[fd]);
	return (left_side_line);
}
