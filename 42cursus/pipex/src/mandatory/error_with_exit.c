/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_with_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn@student.21-school.ru <sserwyn>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:19:55 by sserwyn           #+#    #+#             */
/*   Updated: 2022/04/30 22:28:50 by sserwyn@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	free_cmd_params_array_and_path(char **cmd_params_array, char *path)
{
	int	i;

	i = 0;
	while (cmd_params_array[i])
	{
		free(cmd_params_array[i]);
		i++;
	}
	free(cmd_params_array);
	if (path)
		free(path);
}

void	error_with_exit(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
