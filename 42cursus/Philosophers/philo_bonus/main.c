/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:13:26 by sserwyn           #+#    #+#             */
/*   Updated: 2022/06/04 16:37:49 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_digit_string(char *string)
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

static void	philo(t_philo *philo, t_input_args input_args)
{
	philo->start_time = get_absolute_time();
	philo->last_eat_time = philo->start_time;
	philo->input_args = input_args;
	if (init_sems(philo, input_args.number_of_philosophers) == -1)
	{
		free(philo->pids);
		exit(1);
	}
	start(philo, input_args);
	waitpid(-1, NULL, 0);
	kill(0, SIGINT);
	cleaning_before_exit(philo);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_input_args	input_args;
	t_philo			philos;

	if (argc != 4 + 1 && argc != 5 + 1)
		return (1);
	if (input_args_init(&input_args, argc, argv) != 0)
		return (1);
	philos.pids = (pid_t *)malloc(sizeof(pid_t) * \
		input_args.number_of_philosophers);
	if (!philos.pids)
		return (1);
	philo(&philos, input_args);
	return (0);
}
