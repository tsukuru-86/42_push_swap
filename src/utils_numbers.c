/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:17:12 by tkomai            #+#    #+#             */
/*   Updated: 2025/02/07 12:26:45 by tkomai           ###   ########.fr       */
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

static void	check_overflow(long num, int sign, char c, t_stacks *s)
{
	if (c < '0' || c > '9')
		error_outputs_and_free(s, "Error\n");
	if (sign == 1 && (num > INT_MAX / 10
			|| (num == INT_MAX / 10 && c > '7')))
		error_outputs_and_free(s, "Error\n");
	if (sign == -1 && (num > -(INT_MIN / 10)
			|| (num == -(INT_MIN / 10) && c > '8')))
		error_outputs_and_free(s, "Error\n");
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
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (!str[i] || str[i] < '0' || str[i] > '9')
			error_outputs_and_free(s, "Error\n");
	}
	while (str[i])
	{
		check_overflow(num, sign, str[i], s);
		num = num * 10 + (str[i++] - '0');
	}
	return (num * sign);
}
