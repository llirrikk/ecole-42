/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:29:18 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/05 18:13:34 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	is_strs_identical(char *a, char *b)
{
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	return (ft_strcmp(a, b) == 0);
}

static void	use_instructions_2(t_all *all, char *instruction)
{
	if (is_strs_identical(instruction, "ra") && find_stack_size(all->a) > 0)
		ft_ra(&(all->a), 0);
	else if (is_strs_identical(instruction, "rb") && \
												find_stack_size(all->b) > 0)
		ft_rb(&(all->b), 0);
	else if (is_strs_identical(instruction, "rr"))
	{
		if (find_stack_size(all->a) > 0)
			ft_ra(&(all->a), 0);
		if (find_stack_size(all->b) > 0)
			ft_rb(&(all->b), 0);
	}
	else if (is_strs_identical(instruction, "rra") && \
												find_stack_size(all->a) > 0)
		ft_rra(&(all->a), 0);
	else if (is_strs_identical(instruction, "rrb") && \
												find_stack_size(all->b) > 0)
		ft_rrb(&(all->b), 0);
	else if (is_strs_identical(instruction, "rrr"))
	{
		if (find_stack_size(all->a) > 0)
			ft_rra(&(all->a), 0);
		if (find_stack_size(all->b) > 0)
			ft_rrb(&(all->b), 0);
	}
}

static int	is_real_instruction(char *instruction)
{
	return (is_strs_identical(instruction, "sa") || \
		is_strs_identical(instruction, "sb") || \
		is_strs_identical(instruction, "ss") || \
		is_strs_identical(instruction, "pa") || \
		is_strs_identical(instruction, "pb") || \
		is_strs_identical(instruction, "ra") || \
		is_strs_identical(instruction, "rb") || \
		is_strs_identical(instruction, "rr") || \
		is_strs_identical(instruction, "rra") || \
		is_strs_identical(instruction, "rrb") || \
		is_strs_identical(instruction, "rrr"));
}

void	use_instructions(t_all *all, char *instruction)
{
	if (!is_real_instruction(instruction))
		error_handled_exit(all);
	if (is_strs_identical(instruction, "sa") && \
												find_stack_size(all->a) > 0)
		ft_sa(all->a, 0);
	else if (is_strs_identical(instruction, "sb") && \
												find_stack_size(all->b) > 0)
		ft_sb(all->b, 0);
	else if (is_strs_identical(instruction, "ss"))
	{
		if (find_stack_size(all->a) > 0)
			ft_sa(all->a, 0);
		if (find_stack_size(all->b) > 0)
			ft_sb(all->b, 0);
	}
	else if (is_strs_identical(instruction, "pa") && \
												find_stack_size(all->b) > 0)
		ft_pa(&(all->a), &(all->b), 0);
	else if (is_strs_identical(instruction, "pb") && \
												find_stack_size(all->a) > 0)
		ft_pb(&(all->a), &(all->b), 0);
	else
		use_instructions_2(all, instruction);
}
