/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:21:57 by sserwyn           #+#    #+#             */
/*   Updated: 2022/06/04 16:29:29 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	are_philo_full(t_philo philo, t_eat_times_to_die timestodie)
{
	return (timestodie.is_active && \
		philo.eat_count > timestodie.each_philo_ate_count - 1);
}

int	big_brother(t_philo *philos, t_input_args args)
{
	size_t	i;
	t_bool	need_stop;

	while (true)
	{
		i = -1;
		need_stop = false;
		while (++i < args.number_of_philosophers)
		{
			pthread_mutex_lock(&philos[i].action_mutex);
			if (are_philo_full(philos[i], args.eat_times_to_die))
				need_stop = true;
			pthread_mutex_unlock(&philos[i].action_mutex);
			if (is_philo_died(&philos[i]))
			{
				print_action(&philos[i], DIE);
				return (0);
			}
		}
		if (need_stop)
			return (0);
	}
}

t_bool	is_digit_string(char *string)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(string))
	{
		if (!ft_isdigit(string[i]))
			return (false);
		i++;
	}
	return (true);
}

int	input_args_init(t_input_args *input_args, int argc, char **argv)
{
	if (!(is_digit_string(argv[1]) && is_digit_string(argv[2]) \
		&& is_digit_string(argv[3]) && is_digit_string(argv[4])))
		return (-1);
	input_args->number_of_philosophers = ft_atoi(argv[1]);
	input_args->timings.time_to_die = ft_atoi(argv[2]);
	input_args->timings.time_to_eat = ft_atoi(argv[3]);
	input_args->timings.time_to_sleep = ft_atoi(argv[4]);
	input_args->eat_times_to_die.is_active = false;
	if (argc == 5 + 1)
	{
		if (!is_digit_string(argv[5]))
			return (-1);
		input_args->eat_times_to_die.is_active = true;
		input_args->eat_times_to_die.each_philo_ate_count = ft_atoi(argv[5]);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_input_args	input_args;
	t_more			more;
	t_fork			forks[200];
	t_philo			philos[200];

	if (argc != 4 + 1 && argc != 5 + 1)
		return (1);
	if (input_args_init(&input_args, argc, argv) != 0)
		return (1);
	if (pthread_mutex_init(&more.stdout_mutex, NULL) != 0)
		return (1);
	more.start_time = get_absolute_time();
	if (forks_init(forks, input_args.number_of_philosophers) != 0)
		return (1);
	if (philos_init(philos, forks, input_args, more) != 0)
	{
		ft_forks_destroy(forks, input_args.number_of_philosophers);
		return (1);
	}
	return (big_brother(philos, input_args));
}
