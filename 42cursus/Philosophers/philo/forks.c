/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:22:53 by sserwyn           #+#    #+#             */
/*   Updated: 2022/06/03 15:39:33 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_lock(t_fork *fork)
{
	pthread_mutex_lock(&(fork->mutex));
}

void	fork_unlock(t_fork *fork)
{
	pthread_mutex_unlock(&(fork->mutex));
}

int	forks_init(t_fork *forks, size_t count)
{
	size_t		i;

	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&forks[i].mutex, NULL) != 0)
			return (-1);
		forks[i].number = i;
		i++;
	}
	return (0);
}

void	ft_forks_destroy(t_fork *forks, size_t forks_count)
{
	size_t	i;

	i = 0;
	while (i < forks_count)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		i++;
	}
}
