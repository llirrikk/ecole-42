/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:50:58 by sserwyn           #+#    #+#             */
/*   Updated: 2022/06/04 16:35:47 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eating(t_philo *philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	sem_wait(philo->sems.data_race);
	philo->last_eat_time = now;
	sem_post(philo->sems.data_race);
	print_action(philo, EAT);
	usleep(philo->input_args.timings.time_to_eat * 1000);
	if (!philo->input_args.eat_times_to_die.is_active)
		return ;
	philo->input_args.eat_times_to_die.each_philo_ate_count--;
	if (philo->input_args.eat_times_to_die.each_philo_ate_count == 0)
		sem_post(philo->sems.full_philos_sem);
}

static void	philo_take_forks(t_philo *philo)
{
	sem_wait(philo->sems.avaiable_forks);
	print_action(philo, TAKE_FORK);
	sem_wait(philo->sems.avaiable_forks);
	print_action(philo, TAKE_FORK);
}

void	philo_eat(t_philo *philo)
{
	philo_take_forks(philo);
	philo_eating(philo);
	sem_post(philo->sems.avaiable_forks);
	sem_post(philo->sems.avaiable_forks);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, SLEEP);
	usleep(philo->input_args.timings.time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	print_action(philo, THINK);
}
