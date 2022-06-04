/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:59:49 by sserwyn           #+#    #+#             */
/*   Updated: 2022/05/15 18:42:27 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_relative_time(t_timeval from_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec - from_time.tv_sec) * 1000 \
			+ (time.tv_usec - from_time.tv_usec) / 1000);
}

t_timeval	get_absolute_time(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return (time);
}
