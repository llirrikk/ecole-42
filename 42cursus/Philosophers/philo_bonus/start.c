/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:47:23 by sserwyn           #+#    #+#             */
/*   Updated: 2022/06/04 16:35:47 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*starvation_dead_checker(void *data)
{
	t_philo	*philo;
	size_t	time;

	philo = (t_philo *)data;
	while (true)
	{
		sem_wait(philo->sems.data_race);
		time = get_relative_time(philo->last_eat_time);
		sem_post(philo->sems.data_race);
		if (time > philo->input_args.timings.time_to_die)
		{
			print_action(philo, DIE);
			break ;
		}
		usleep(500);
	}
	exit(0);
}

static void	routine(t_philo *philo)
{
	pthread_t	death_check;

	pthread_create(&death_check, NULL, &starvation_dead_checker, philo);
	pthread_detach(death_check);
	while (true)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

static void	full_philos_checker(t_philo *philo, size_t number_of_philosophers)
{
	pid_t	_philos_full_checker;
	size_t	i;

	if (!philo->input_args.eat_times_to_die.is_active)
		return ;
	_philos_full_checker = fork();
	if (_philos_full_checker != 0)
		return ;
	i = 0;
	while (i < number_of_philosophers)
	{
		sem_wait(philo->sems.full_philos_sem);
		i++;
	}
	sem_wait(philo->sems.stdout_sem);
	cleaning_before_exit(philo);
	exit(0);
}

void	start(t_philo *philo, t_input_args args)
{
	philo->number = 1;
	while (philo->number < args.number_of_philosophers + 1)
	{
		philo->pids[philo->number] = fork();
		if (philo->pids[philo->number] == 0)
		{
			if (philo->number % 2 == 0)
				usleep(2500);
			routine(philo);
		}
		philo->number++;
	}
	full_philos_checker(philo, args.number_of_philosophers);
}
