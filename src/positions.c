/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 00:00:00 by tsukuru           #+#    #+#             */
/*   Updated: 2026/08/29 00:00:00 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_min_position(t_stack *stack)
{
	int	position;
	int	index;

	position = 0;
	index = 1;
	while (index < stack->size)
	{
		if (stack->data[index] < stack->data[position])
			position = index;
		index++;
	}
	return (position);
}

int	ps_max_position(t_stack *stack)
{
	int	position;
	int	index;

	position = 0;
	index = 1;
	while (index < stack->size)
	{
		if (stack->data[index] > stack->data[position])
			position = index;
		index++;
	}
	return (position);
}
