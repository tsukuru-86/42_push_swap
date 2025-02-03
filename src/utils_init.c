/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:17:12 by tkomai            #+#    #+#             */
/*   Updated: 2025/02/03 18:01:44 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_stacks(int argc, char **argv, t_stacks *s)
{
	(void)argv;
	if (argc < 2)
		error_outputs_and_free(s, "Error\n");
	s->a_size = count_box(s->join_args, ' ');
	if (s->a_size == 0)
		error_outputs_and_free(s, "Error\n");
	s->a = malloc(s->a_size * sizeof * s->a);
	if (s->a == NULL)
		error_outputs_and_free(s, "Error\n");
	s->b = malloc(s->b_size * sizeof * s->b);
	if (s->b == NULL)
		error_outputs_and_free(s, "E ror\n");
}

void	atoi_numbers(t_stacks *s)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	tmp = ft_split(s->join_args, ' ');
	i = 0;
	while (tmp[i] != NULL)
	{
		s->a[z++] = ft_atol(tmp[i++], s);
		free(tmp[i - 1]);
	}
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
