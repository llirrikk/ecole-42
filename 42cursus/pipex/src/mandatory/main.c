/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn@student.21-school.ru <sserwyn>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:40:48 by sserwyn           #+#    #+#             */
/*   Updated: 2022/04/30 21:57:05 by sserwyn@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	child_process_from(int *fd, char **argv, char **envp)
{
	int	fd_file_from;

	fd_file_from = open(argv[1], O_RDONLY, 0777);
	if (fd_file_from == -1)
		error_with_exit();
	close(fd[0]);
	if (dup2(fd_file_from, STDIN_FILENO) == -1)
		error_with_exit();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error_with_exit();
	if (ft_exec(argv[2], envp) == ERROR_RETURN_CODE)
		error_with_exit();
	close(fd[1]);
}

void	child_process_to(int *fd, char **argv, char **envp)
{
	int	fd_file_to;

	fd_file_to = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_file_to == -1)
		error_with_exit();
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error_with_exit();
	if (dup2(fd_file_to, STDOUT_FILENO) == -1)
		error_with_exit();
	if (ft_exec(argv[3], envp) == ERROR_RETURN_CODE)
		error_with_exit();
	close(fd[0]);
}

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		error_with_exit();
	pid1 = fork();
	if (pid1 == -1)
		error_with_exit();
	if (pid1 == 0)
		child_process_from(fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		error_with_exit();
	if (pid2 == 0)
		child_process_to(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr("Usage: ./pipex infile cmd1 cmd2 outfile\n");
		return (1);
	}
	pipex(argv, envp);
	return (0);
}
