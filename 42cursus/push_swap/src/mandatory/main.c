/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:16:21 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/05 22:09:24 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	stack_sort(t_all all)
{
	push_all_to_b_except_min_max_med(&all);
	sort_3_stack_elems(&all.a);
	while (find_stack_size(all.b) > 0)
	{	
		find_b_to_a_points(&all);
		move_to_a_min_point(&all);
	}
	init_expected_moves(&all);
	move_element_to_top_of_stack(&all.a, \
								find_index_from_value(all.a, all.min), 1, &all);
	make_moves_via_expected_moves(&all);
}

static void	if_only_2_args(int argc, char **argv)
{
	int	first;
	int	second;

	if (argc == 2 + 1)
	{
		first = ft_atoi(argv[1]);
		second = ft_atoi(argv[2]);
		if (second < first)
		{
			write(1, "sa\n", 3);
			exit(0);
		}
	}
}

static void	if_only_5_args(t_all all)
{
	if (all.argc != 5 + 1)
		return ;
	find_min_max_med(&all);
	if (find_index_from_value(all.a, all.min) > 2)
		while (find_index_from_value(all.a, all.min) != 0)
			ft_rra(&(all.a), 1);
	else
		while (find_index_from_value(all.a, all.min) != 0)
			ft_ra(&(all.a), 1);
	ft_pb(&(all.a), &(all.b), 1);
	if (find_index_from_value(all.a, all.max) > 2)
		while (find_index_from_value(all.a, all.max) != 0)
			ft_rra(&(all.a), 1);
	else
		while (find_index_from_value(all.a, all.max) != 0)
			ft_ra(&(all.a), 1);
	ft_pb(&(all.a), &(all.b), 1);
	sort_3_stack_elems(&(all.a));
	ft_pa(&(all.a), &(all.b), 1);
	ft_ra(&(all.a), 1);
	ft_pa(&(all.a), &(all.b), 1);
	handled_exit(&all);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc < 2)
		return (1);
	if (!is_args_valid(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if_only_2_args(argc, argv);
	all.argc = argc;
	all.argv = argv;
	all.a = NULL;
	all.b = NULL;
	parse_to_stack(&all);
	if (is_stack_sorted(all.a))
		handled_exit(&all);
	if_only_5_args(all);
	stack_sort(all);
	handled_exit(&all);
}
