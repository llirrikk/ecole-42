/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:53:12 by sserwyn           #+#    #+#             */
/*   Updated: 2022/03/07 21:29:57 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_expected_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_expected_moves;

typedef struct s_stack
{
	int				value;
	int				move_point;
	struct s_stack	*next;
}	t_stack;

typedef struct s_all
{
	int						argc;
	char					**argv;
	struct s_stack			*a;
	struct s_stack			*b;

	int						min;
	int						max;
	int						med;

	struct s_expected_moves	expected_moves;
}	t_all;

void		ft_list_push_back(t_stack **begin_list, int data);
void		ft_lstclear(t_stack **lst);
int			ft_atoi(const char *str);
void		ft_swap(int *a, int *b);

void		push_all_to_b_except_min_max_med(t_all *all);
void		sort_3_stack_elems(t_stack **stack);
void		find_min_max_med(t_all *all);

int			find_index_from_value(t_stack *stack, int value);
int			find_value_from_index(t_stack *stack, int index);
int			find_stack_size(t_stack *stack);
void		parse_to_stack(t_all *all);
int			is_stack_sorted(t_stack *stack);

void		prepare_a_to_put_in(t_stack **a, int element_to_put, t_all *all);
int			find_right_index_from_top_in_a(t_stack *a, int value_in_b);

void		move_element_to_top_of_stack(t_stack **stack, int index, \
										int a_or_b, t_all *all);
int			find_point_to_raise_up(t_stack *stack, int element);

void		make_moves_via_expected_moves(t_all *all);
void		init_expected_moves(t_all *all);

void		find_b_to_a_points(t_all *all);
void		move_to_a_min_point(t_all *all);

void		ft_ra(t_stack **a, int is_print);
void		ft_rb(t_stack **b, int is_print);
void		ft_rr(t_stack **a, t_stack **b, int is_print);

void		ft_rra(t_stack **a, int is_print);
void		ft_rrb(t_stack **b, int is_print);
void		ft_rrr(t_stack **a, t_stack **b, int is_print);

void		ft_sa(t_stack *a, int is_print);
void		ft_sb(t_stack *b, int is_print);
void		ft_ss(t_stack *a, t_stack *b, int is_print);

void		ft_pa(t_stack **a, t_stack **b, int is_print);
void		ft_pb(t_stack **a, t_stack **b, int is_print);

int			is_args_valid(int argc, char **argv);

char		*get_next_line(int fd);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
long int	ft_atol(const char *str);
void		use_instructions(t_all *all, char *instruction);
void		handled_exit(t_all *all);
void		error_handled_exit(t_all *all);

#endif