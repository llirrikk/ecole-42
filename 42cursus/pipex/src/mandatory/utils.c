/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn@student.21-school.ru <sserwyn>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:45:04 by sserwyn           #+#    #+#             */
/*   Updated: 2022/04/30 22:35:12 by sserwyn@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*get_path_var_from_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	return (envp[i]);
}

void	free_paths_array(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	*get_path_to_cmd_from_path_var(char *path_var, char *cmd)
{
	char	**paths;
	int		i;
	char	*dirname;
	char	*dircmd;

	paths = ft_split(path_var + 5, ':');
	i = 0;
	while (paths[i])
	{
		dirname = ft_strjoin(paths[i], "/");
		dircmd = ft_strjoin(dirname, cmd);
		free(dirname);
		if (access(dircmd, F_OK) == 0)
		{
			free_paths_array(paths);
			return (dircmd);
		}
		else
			free(dircmd);
		i++;
	}
	free_paths_array(paths);
	return (NULL);
}

int	ft_exec(char *cmd_with_params_str, char **envp)
{
	char	*path_to_cmd;
	char	*path_var;
	char	**cmd_with_params_array;

	cmd_with_params_array = ft_split(cmd_with_params_str, ' ');
	path_var = get_path_var_from_envp(envp);
	path_to_cmd = get_path_to_cmd_from_path_var(path_var, \
												cmd_with_params_array[0]);
	if (NULL == path_to_cmd)
	{
		free_cmd_params_array_and_path(cmd_with_params_array, path_to_cmd);
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	execve(path_to_cmd, cmd_with_params_array, envp);
	free_cmd_params_array_and_path(cmd_with_params_array, path_to_cmd);
	error_with_exit();
	return (0);
}
