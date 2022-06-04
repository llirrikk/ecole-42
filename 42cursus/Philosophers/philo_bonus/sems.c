/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sems.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:36:09 by sserwyn           #+#    #+#             */
/*   Updated: 2022/06/04 16:17:42 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_sems(t_philo *philo, size_t nbr_of_philosophers)
{
	sem_unlink("/forks");
	sem_unlink("/dinner");
	sem_unlink("/to_print");
	sem_unlink("/check_data_race");
	philo->sems.avaiable_forks = sem_open("/forks", O_CREAT, S_IRWXU, \
											nbr_of_philosophers);
	if (philo->sems.avaiable_forks == SEM_FAILED)
		return (-1);
	philo->sems.full_philos_sem = sem_open("/dinner", O_CREAT, S_IRWXU, 0);
	if (philo->sems.full_philos_sem == SEM_FAILED)
		return (-1);
	philo->sems.stdout_sem = sem_open("/to_print", O_CREAT, S_IRWXU, 1);
	if (philo->sems.stdout_sem == SEM_FAILED)
		return (-1);
	philo->sems.data_race = sem_open("/check_data_race", O_CREAT, S_IRWXU, 1);
	if (philo->sems.data_race == SEM_FAILED)
		return (-1);
	return (0);
}
