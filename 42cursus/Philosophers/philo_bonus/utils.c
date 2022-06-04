/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:07:58 by sserwyn           #+#    #+#             */
/*   Updated: 2022/06/04 16:08:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleaning_before_exit(t_philo *philo)
{
	sem_close(philo->sems.avaiable_forks);
	sem_close(philo->sems.full_philos_sem);
	sem_close(philo->sems.stdout_sem);
	sem_close(philo->sems.data_race);
	free(philo->pids);
}
