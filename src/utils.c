/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 04:24:25 by tsukuru           #+#    #+#             */
/*   Updated: 2025/02/02 18:06:39 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//同じ数字が入っていないか、既にソートされていないかをチェック
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
	//関数でソートできているかどうかのチェックは後で分離
	if (is_array_sorted(s))
		error_outputs_and_free(s, NULL);
}

//ソートされているかのチェック
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

//stackAとBを確保
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
		error_outputs_and_free(s, "Error\n");
}

//文字列を　"77 6 7878 8 23 7"のような数値に変換
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

void	create_index(t_stacks *s)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(s->a_size * sizeof(int));
	if (new_a == NULL)
		error_outputs_and_free(s, "Error\n");
	i = 0;
	while (i < s->a_size)
	{
		j = 0;
		k = 0;
		while (j < s->a_size)
		{
			if (s->a[i] > s->a[j])
				k++;
			j++;
		}
		new_a[i] = k;
		i++;
	}
	i = 0;
	while (i < s->a_size)
	{
		s->a[i] = new_a[i];
		i++;
	}
	free(new_a);
}

int ft_atol(const char *n, t_stacks *s)
{
	int i;
	long sign;
	long long res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if ((n[i] == '+' || n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		if (res > 2147483647 || (res * sign) < -2147483648 || ft_strlen(n) > 11)
			error_outputs_and_free(s, "Error\n");
		if (!(n[i] >= '0' && n[i] <= '9'))
			error_outputs_and_free(s, "Error\n");
		res = res * 10 + (n[i++] - '0');
	}
	return ((int)(res * sign));
}
