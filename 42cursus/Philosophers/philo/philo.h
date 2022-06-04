/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:22:52 by sserwyn           #+#    #+#             */
/*   Updated: 2022/06/04 16:35:47 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

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

typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

struct s_timings
{
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
};
typedef struct s_eat_times_to_die
{
	size_t	each_philo_ate_count;
	t_bool	is_active;
}	t_eat_times_to_die;
typedef struct s_input_args
{
	size_t						number_of_philosophers;
	struct s_timings			timings;
	struct s_eat_times_to_die	eat_times_to_die;
}	t_input_args;

typedef struct s_fork
{
	size_t	number;
	t_mutex	mutex;
}	t_fork;

typedef struct s_more
{
	t_mutex		stdout_mutex;
	t_timeval	start_time;
}	t_more;
typedef struct s_hands
{
	struct s_fork	*left;
	struct s_fork	*right;
}	t_hands;
typedef struct s_philo
{
	size_t				number;
	struct s_hands		hands;
	struct s_input_args	input_args;
	t_mutex				action_mutex;
	size_t				eat_count;
	t_timeval			last_eat_time;
	struct s_more		more;
}	t_philo;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
size_t		ft_strlen(char *str);

void		fork_lock(t_fork *fork);
void		fork_unlock(t_fork *fork);
int			forks_init(t_fork *forks, size_t count);
void		ft_forks_destroy(t_fork *forks, size_t forks_count);
void		print_action(t_philo *philo, t_action action);
t_timeval	get_absolute_time(void);
size_t		get_relative_time(t_timeval from_time);
t_bool		is_philo_died(t_philo *philo);
void		update_last_eat_time(t_philo *philo, t_bool was_sleeping);
t_bool		are_each_philo_ate_count_times(t_philo *philos, size_t philo_count, \
	size_t number_of_times_each_philosopher_must_eat);

void		*philo_simulation(void *data);
int			philos_init(t_philo *philos, t_fork *forks, \
						t_input_args args, t_more more);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_eat(t_philo *philo, t_bool was_sleeping);

t_timeval	get_absolute_time(void);
size_t		get_relative_time(t_timeval from_time);

#endif
