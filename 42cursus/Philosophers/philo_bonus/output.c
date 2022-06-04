/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:00:17 by sserwyn           #+#    #+#             */
/*   Updated: 2022/06/04 16:02:29 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, t_action action)
{
	sem_wait(philo->sems.stdout_sem);
	if (action == TAKE_FORK)
		printf("%ld %zu has taken a fork\n", \
			get_relative_time(philo->start_time), philo->number);
	else if (action == EAT)
		printf("%ld %zu is eating\n", \
			get_relative_time(philo->start_time), philo->number);
	else if (action == SLEEP)
		printf("%ld %zu is sleeping\n", \
			get_relative_time(philo->start_time), philo->number);
	else if (action == THINK)
		printf("%ld %zu is thinking\n", \
			get_relative_time(philo->start_time), philo->number);
	else if (action == DIE)
		printf("%ld %zu died\n", \
			get_relative_time(philo->start_time), philo->number);
	sem_post(philo->sems.stdout_sem);
}
