/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn@student.21-school.ru <sserwyn>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:53:53 by sserwyn           #+#    #+#             */
/*   Updated: 2022/04/16 23:49:48 by sserwyn@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

# define ERROR_RETURN_CODE -1

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	free_cmd_params_array_and_path(char **cmd_params_array, char *path);

void	error_with_exit(void);
int		ft_exec(char *cmd, char **envp);
int		ft_strlen(char *str);
void	ft_putstr(char *str);

#endif
