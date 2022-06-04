/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:48:32 by sserwyn           #+#    #+#             */
/*   Updated: 2022/05/15 18:42:38 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_define_max_min_fork(t_hands hands, t_fork **min, t_fork **max)
{
	*min = hands.right;
	*max = hands.left;
	if (hands.left->number < hands.right->number)
	{
		*min = hands.left;
		*max = hands.right;
	}
}

void	philo_eat(t_philo *philo, t_bool was_sleeping)
{
	t_fork	*min_fork;
	t_fork	*max_fork;

	philo_define_max_min_fork(philo->hands, &min_fork, &max_fork);
	fork_lock(min_fork);
	print_action(philo, TAKE_FORK);
	fork_lock(max_fork);
	print_action(philo, TAKE_FORK);
	print_action(philo, EAT);
	usleep(philo->input_args.timings.time_to_eat * 1000);
	pthread_mutex_lock(&(philo->action_mutex));
	philo->eat_count++;
	update_last_eat_time(philo, was_sleeping);
	pthread_mutex_unlock(&(philo->action_mutex));
	fork_unlock(max_fork);
	fork_unlock(min_fork);
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
