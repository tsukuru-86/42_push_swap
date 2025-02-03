/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:17:12 by tkomai            #+#    #+#             */
/*   Updated: 2025/02/04 05:02:27 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_numbers(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

void	check_numbers(t_stacks *s, int i)
{
	int	j;

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
	if (is_array_sorted(s))
		exit(0);
}

int	is_array_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	create_index(t_stacks *s)
{
	int	i;
	int	j;
	int	*tmp;

	tmp = malloc(sizeof(int) * s->a_size);
	if (!tmp)
		error_outputs_and_free(s, "Error\n");
	i = -1;
	while (++i < s->a_size)
	{
		j = -1;
		tmp[i] = 0;
		while (++j < s->a_size)
			if (s->a[i] > s->a[j])
				tmp[i]++;
	}
	i = -1;
	while (++i < s->a_size)
		s->a[i] = tmp[i];
	free(tmp);
}

int	ft_atol(const char *str, t_stacks *s)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' && str[i++])
		sign = -1;
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9' || (sign == 1 && (num > INT_MAX / 10
					|| (num == INT_MAX / 10 && str[i] > '7'))) || (sign == -1
				&& (num > -(INT_MIN / 10) || (num == -(INT_MIN / 10)
						&& str[i] > '8'))))
			error_outputs_and_free(s, "Error\n");
		num = num * 10 + (str[i++] - '0');
	}
	return ((int)(num * sign));
}
