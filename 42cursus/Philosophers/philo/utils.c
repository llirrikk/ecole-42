/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:22:49 by sserwyn           #+#    #+#             */
/*   Updated: 2022/05/15 18:42:24 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_philo_died(t_philo *philo)
{
	t_timeval	current_time;

	current_time = get_absolute_time();
	pthread_mutex_lock(&philo->action_mutex);
	if ((current_time.tv_sec - philo->last_eat_time.tv_sec) * 1000
		+ (current_time.tv_usec - philo->last_eat_time.tv_usec + 500) / 1000
		>= (long) philo->input_args.timings.time_to_die)
	{
		pthread_mutex_unlock(&philo->action_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->action_mutex);
	return (false);
}

static void	last_eat_time_inc(t_timeval *time, size_t increment)
{
	time->tv_sec += increment * 1000;
	if (time->tv_usec >= 100000)
	{
		time->tv_sec++;
		time->tv_usec -= 100000;
	}
}

void	update_last_eat_time(t_philo *philo, t_bool was_sleeping)
{
	last_eat_time_inc(&philo->last_eat_time, \
						philo->input_args.timings.time_to_eat);
	if (was_sleeping)
		last_eat_time_inc(&philo->last_eat_time, \
							philo->input_args.timings.time_to_sleep);
}

t_bool	are_each_philo_ate_count_times(t_philo *philos, size_t philo_count, \
							size_t number_of_times_each_philosopher_must_eat)
{
	size_t	i;

	i = 0;
	while (i < philo_count)
	{
		if (philos[i].eat_count < number_of_times_each_philosopher_must_eat)
			return (false);
		i++;
	}
	return (true);
}

void	print_action(t_philo *philo, t_action action)
{
	pthread_mutex_lock(&(philo->more.stdout_mutex));
	if (action == TAKE_FORK)
		printf("%ld %zu has taken a fork\n", \
			get_relative_time(philo->more.start_time), philo->number);
	else if (action == EAT)
		printf("%ld %zu is eating\n", \
			get_relative_time(philo->more.start_time), philo->number);
	else if (action == SLEEP)
		printf("%ld %zu is sleeping\n", \
			get_relative_time(philo->more.start_time), philo->number);
	else if (action == THINK)
		printf("%ld %zu is thinking\n", \
			get_relative_time(philo->more.start_time), philo->number);
	else if (action == DIE)
		printf("%ld %zu died\n", \
			get_relative_time(philo->more.start_time), philo->number);
	pthread_mutex_unlock(&(philo->more.stdout_mutex));
}
