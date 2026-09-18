/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 00:00:00 by tsukuru           #+#    #+#             */
/*   Updated: 2026/08/29 00:00:00 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_stack(t_stack *stack)
{
	int	temporary;

	if (stack->size < 2)
		return ;
	temporary = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = temporary;
}

static void	push_stack(t_stack *destination, t_stack *source)
{
	int	index;

	if (source->size == 0)
		return ;
	index = destination->size;
	while (index > 0)
	{
		destination->data[index] = destination->data[index - 1];
		index--;
	}
	destination->data[0] = source->data[0];
	destination->size++;
	index = -1;
	while (++index + 1 < source->size)
		source->data[index] = source->data[index + 1];
	source->size--;
}

static void	rotate_stack(t_stack *stack, int reverse)
{
	int	temporary;
	int	index;

	if (stack->size < 2)
		return ;
	if (reverse)
	{
		temporary = stack->data[stack->size - 1];
		index = stack->size - 1;
		while (index > 0)
		{
			stack->data[index] = stack->data[index - 1];
			index--;
		}
		stack->data[0] = temporary;
	}
	else
	{
		temporary = stack->data[0];
		index = 0;
		while (++index < stack->size)
			stack->data[index - 1] = stack->data[index];
		stack->data[stack->size - 1] = temporary;
	}
}

static void	write_operation(int operation)
{
	const char	*names[11];
	int			length;

	names[OP_SA] = "sa\n";
	names[OP_SB] = "sb\n";
	names[OP_SS] = "ss\n";
	names[OP_PA] = "pa\n";
	names[OP_PB] = "pb\n";
	names[OP_RA] = "ra\n";
	names[OP_RB] = "rb\n";
	names[OP_RR] = "rr\n";
	names[OP_RRA] = "rra\n";
	names[OP_RRB] = "rrb\n";
	names[OP_RRR] = "rrr\n";
	length = 3;
	if (operation >= OP_RRA)
		length = 4;
	write(1, names[operation], length);
}

void	ps_execute(t_stacks *s, int operation, int print)
{
	if (operation == OP_SA || operation == OP_SS)
		swap_stack(&s->a);
	if (operation == OP_SB || operation == OP_SS)
		swap_stack(&s->b);
	if (operation == OP_PA)
		push_stack(&s->a, &s->b);
	if (operation == OP_PB)
		push_stack(&s->b, &s->a);
	if (operation == OP_RA || operation == OP_RR)
		rotate_stack(&s->a, 0);
	if (operation == OP_RB || operation == OP_RR)
		rotate_stack(&s->b, 0);
	if (operation == OP_RRA || operation == OP_RRR)
		rotate_stack(&s->a, 1);
	if (operation == OP_RRB || operation == OP_RRR)
		rotate_stack(&s->b, 1);
	if (print)
		write_operation(operation);
}
