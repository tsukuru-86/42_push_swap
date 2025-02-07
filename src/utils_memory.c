/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:17:12 by tkomai            #+#    #+#             */
/*   Updated: 2025/02/07 12:09:20 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacks(t_stacks *s)
{
	if (s != NULL)
	{
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s->join_args != NULL)
			free(s->join_args);
		free(s);
	}
}

void	error_outputs_and_free(t_stacks *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	free_stacks(s);
	exit(1);
}

char	*join_args_helper(char *tmp2, char *argv_i, t_stacks *s)
{
	char	*tmp;

	tmp = ft_strjoin(tmp2, argv_i);
	free(tmp2);
	if (!tmp)
		error_outputs_and_free(s, "Error\n");
	return (tmp);
}

void	initialize_stacks(int argc, char **argv, t_stacks *s)
{
	(void)argv;
	if (argc < 2)
		error_outputs_and_free(s, "Error\n");
	s->a_size = count_numbers(s->join_args, ' ');
	if (s->a_size == 0)
		error_outputs_and_free(s, "Error\n");
	s->b_size = 0;
	s->a = malloc(s->a_size * sizeof * s->a);
	if (s->a == NULL)
		error_outputs_and_free(s, "Error\n");
	s->b = malloc((s->a_size) * sizeof * s->b);
	if (s->b == NULL)
		error_outputs_and_free(s, "Error\n");
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
