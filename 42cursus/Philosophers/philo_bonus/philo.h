/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:17:14 by sserwyn           #+#    #+#             */
/*   Updated: 2022/06/04 16:36:36 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <pthread.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_actions
{
	TAKE_FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_action;

typedef struct timeval	t_timeval;

struct s_timings
{
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
};
struct s_eat_times_to_die
{
	size_t	each_philo_ate_count;
	t_bool	is_active;
};
typedef struct s_input_args
{
	size_t						number_of_philosophers;
	struct s_timings			timings;
	struct s_eat_times_to_die	eat_times_to_die;
}	t_input_args;

struct s_semaphores
{
	sem_t	*avaiable_forks;
	sem_t	*full_philos_sem;
	sem_t	*stdout_sem;
	sem_t	*data_race;
};
typedef struct s_philo
{
	size_t				number;
	pid_t				*pids;
	t_timeval			start_time;
	t_timeval			last_eat_time;
	struct s_semaphores	sems;
	struct s_input_args	input_args;
}	t_philo;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
size_t		ft_strlen(char *str);

t_timeval	get_absolute_time(void);
size_t		get_relative_time(t_timeval from_time);
void		cleaning_before_exit(t_philo *philo);

int			init_sems(t_philo *philo, size_t nbr_of_philosophers);

void		start(t_philo *philo, t_input_args args);

void		print_action(t_philo *philo, t_action action);

void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

#endif
