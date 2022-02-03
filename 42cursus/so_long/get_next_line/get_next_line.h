/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:26:23 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/26 22:33:16 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42

# include <stdlib.h>
# include <unistd.h>

size_t	strlen_to_first_endl(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2, char **free_s1);
int		ft_strlen(char *str);

char	*get_next_line(int fd);

#endif
