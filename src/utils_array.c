/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 04:24:25 by tsukuru           #+#    #+#             */
/*   Updated: 2025/02/03 18:03:48 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_numbers(t_stacks *s, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < s->a_size)
		{
			j = i + 1;
			while (j < s->a_size)
			{
				if (s->a[i] == s->a[j])
					error_outputs_and_free(s, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(s))
		error_outputs_and_free(s, NULL);
}

int	is_array_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	create_index(t_stacks *s)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(s->a_size * sizeof(int));
	if (new_a == NULL)
		error_outputs_and_free(s, "Error\n");
	i = -1;
	while (++i < s->a_size)
	{
		j = -1;
		k = 0;
		while (++j < s->a_size)
		{
			if (s->a[i] > s->a[j])
				k++;
		}
		new_a[i] = k;
	}
	i = -1;
	while (++i < s->a_size)
		s->a[i] = new_a[i];
	free(new_a);
}
