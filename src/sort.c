/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 00:00:00 by tsukuru           #+#    #+#             */
/*   Updated: 2026/08/29 00:00:00 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_sort_three(t_stacks *stacks)
{
	int	*a;

	a = stacks->a.data;
	if (a[0] > a[1] && a[0] > a[2])
		ps_execute(stacks, OP_RA, 1);
	else if (a[1] > a[0] && a[1] > a[2])
		ps_execute(stacks, OP_RRA, 1);
	if (stacks->a.data[0] > stacks->a.data[1])
		ps_execute(stacks, OP_SA, 1);
}

static void	move_to_top(t_stacks *stacks, int position, int stack_b)
{
	t_stack	*stack;
	int		up;
	int		down;

	stack = &stacks->a;
	if (stack_b)
		stack = &stacks->b;
	up = OP_RA + stack_b;
	down = OP_RRA + stack_b;
	if (position <= stack->size / 2)
		while (position-- > 0)
			ps_execute(stacks, up, 1);
	else
	{
		position = stack->size - position;
		while (position-- > 0)
			ps_execute(stacks, down, 1);
	}
}

static void	sort_small(t_stacks *stacks)
{
	int	position;

	if (stacks->a.size == 2)
		ps_execute(stacks, OP_SA, 1);
	while (stacks->a.size > 3)
	{
		position = ps_min_position(&stacks->a);
		move_to_top(stacks, position, 0);
		ps_execute(stacks, OP_PB, 1);
	}
	if (stacks->a.size == 3)
		ps_sort_three(stacks);
	while (stacks->b.size > 0)
		ps_execute(stacks, OP_PA, 1);
}

static void	sort_chunks(t_stacks *stacks)
{
	int	chunk;
	int	pushed;

	chunk = 14;
	if (stacks->a.size > 100)
		chunk = 30;
	pushed = 0;
	while (stacks->a.size > 0)
	{
		if (stacks->a.data[0] <= pushed)
		{
			ps_execute(stacks, OP_PB, 1);
			ps_execute(stacks, OP_RB, 1);
			pushed++;
		}
		else if (stacks->a.data[0] <= pushed + chunk)
		{
			ps_execute(stacks, OP_PB, 1);
			pushed++;
		}
		else
			ps_execute(stacks, OP_RA, 1);
	}
}

void	ps_sort(t_stacks *stacks)
{
	int	position;

	if (stacks->a.size <= 5)
	{
		sort_small(stacks);
		return ;
	}
	sort_chunks(stacks);
	while (stacks->b.size > 0)
	{
		position = ps_max_position(&stacks->b);
		move_to_top(stacks, position, 1);
		ps_execute(stacks, OP_PA, 1);
	}
}
