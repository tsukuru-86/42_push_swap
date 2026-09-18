/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 00:00:00 by tsukuru           #+#    #+#             */
/*   Updated: 2026/08/29 00:00:00 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_initialize(t_stacks *stacks)
{
	stacks->a.data = NULL;
	stacks->a.size = 0;
	stacks->b.data = NULL;
	stacks->b.size = 0;
}

void	ps_free(t_stacks *stacks)
{
	free(stacks->a.data);
	free(stacks->b.data);
	stacks->a.data = NULL;
	stacks->b.data = NULL;
}

int	ps_is_sorted(t_stack *stack)
{
	int	index;

	index = 0;
	while (index + 1 < stack->size)
	{
		if (stack->data[index] >= stack->data[index + 1])
			return (0);
		index++;
	}
	return (1);
}

int	ps_has_duplicates(t_stack *stack)
{
	int	index;
	int	other;

	index = -1;
	while (++index < stack->size)
	{
		other = index;
		while (++other < stack->size)
			if (stack->data[index] == stack->data[other])
				return (1);
	}
	return (0);
}

int	ps_create_indexes(t_stack *stack)
{
	int	*indexes;
	int	index;
	int	other;

	indexes = malloc(sizeof(int) * stack->size);
	if (!indexes)
		return (0);
	index = -1;
	while (++index < stack->size)
	{
		indexes[index] = 0;
		other = -1;
		while (++other < stack->size)
			if (stack->data[index] > stack->data[other])
				indexes[index]++;
	}
	index = -1;
	while (++index < stack->size)
		stack->data[index] = indexes[index];
	free(indexes);
	return (1);
}
