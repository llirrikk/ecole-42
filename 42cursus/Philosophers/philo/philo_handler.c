/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:49:22 by sserwyn           #+#    #+#             */
/*   Updated: 2022/06/04 16:35:47 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philos_init(t_philo *philos, t_fork *forks, t_input_args args, t_more more)
{
	pthread_t	_ptid;
	size_t		i;

	i = 0;
	while (i < args.number_of_philosophers)
	{
		philos[i].hands.left = &(forks[i]);
		philos[i].hands.right = &(forks[(i + 1) % args.number_of_philosophers]);
		philos[i].number = i + 1;
		philos[i].input_args = args;
		if (pthread_mutex_init(&philos[i].action_mutex, NULL) != 0)
			return (-1);
		philos[i].eat_count = 0;
		philos[i].last_eat_time = more.start_time;
		philos[i].more = more;
		if (pthread_create(&_ptid, NULL, philo_simulation, &(philos[i])) != 0)
		{
			pthread_mutex_destroy(&philos[0].action_mutex);
			return (-1);
		}
		pthread_detach(_ptid);
		i++;
	}
	return (0);
}

void	*philo_simulation(void *data)
{
	if (((t_philo *)data)->number % 2 == 0)
		usleep(2500);
	philo_eat((t_philo *)data, false);
	philo_sleep((t_philo *)data);
	philo_think((t_philo *)data);
	while (1)
	{
		philo_eat((t_philo *)data, true);
		philo_sleep((t_philo *)data);
		philo_think((t_philo *)data);
	}
}
