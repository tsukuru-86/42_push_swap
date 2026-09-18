/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 00:00:00 by tsukuru           #+#    #+#             */
/*   Updated: 2026/08/29 00:00:00 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_space(char character)
{
	return (character == ' ' || (character >= '\t' && character <= '\r'));
}

static int	count_numbers(const char *text)
{
	int	count;

	count = 0;
	while (*text)
	{
		while (is_space(*text))
			text++;
		if (!*text)
			break ;
		if (*text == '+' || *text == '-')
			text++;
		if (*text < '0' || *text > '9')
			return (-1);
		while (*text >= '0' && *text <= '9')
			text++;
		if (*text && !is_space(*text))
			return (-1);
		count++;
	}
	return (count);
}

static int	parse_number(const char **text, int *number)
{
	long	value;
	int		sign;

	while (is_space(**text))
		(*text)++;
	sign = 1;
	if (**text == '+' || **text == '-')
	{
		if (*(*text)++ == '-')
			sign = -1;
	}
	value = 0;
	while (**text >= '0' && **text <= '9')
	{
		if (value > (LONG_MAX - (**text - '0')) / 10)
			return (0);
		value = value * 10 + **text - '0';
		(*text)++;
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && value > -(long)INT_MIN))
			return (0);
	}
	*number = (int)(value * sign);
	return (1);
}

static int	fill_stack(int argc, char **argv, t_stack *stack)
{
	const char	*text;
	int			argument;

	argument = 1;
	while (argument < argc)
	{
		text = argv[argument++];
		while (*text)
		{
			while (is_space(*text))
				text++;
			if (*text && !parse_number(&text, &stack->data[stack->size++]))
				return (0);
		}
	}
	return (1);
}

int	ps_parse_arguments(int argc, char **argv, t_stacks *stacks)
{
	int	argument;
	int	count;
	int	amount;

	ps_initialize(stacks);
	count = 0;
	argument = 0;
	while (++argument < argc)
	{
		amount = count_numbers(argv[argument]);
		if (amount <= 0)
			return (0);
		count += amount;
	}
	stacks->a.data = malloc(sizeof(int) * count);
	stacks->b.data = malloc(sizeof(int) * count);
	if (!stacks->a.data || !stacks->b.data)
		return (ps_free(stacks), 0);
	if (!fill_stack(argc, argv, &stacks->a))
		return (ps_free(stacks), 0);
	return (1);
}
