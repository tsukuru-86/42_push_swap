/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 00:00:00 by tsukuru           #+#    #+#             */
/*   Updated: 2026/08/29 00:00:00 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
};

int		ps_parse_arguments(int argc, char **argv, t_stacks *stacks);
void	ps_initialize(t_stacks *stacks);
void	ps_free(t_stacks *stacks);
int		ps_is_sorted(t_stack *stack);
int		ps_has_duplicates(t_stack *stack);
int		ps_create_indexes(t_stack *stack);
void	ps_execute(t_stacks *stacks, int operation, int print);
void	ps_sort(t_stacks *stacks);
void	ps_sort_three(t_stacks *stacks);
int		ps_min_position(t_stack *stack);
int		ps_max_position(t_stack *stack);

#endif
