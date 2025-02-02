/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:27:26 by tkomai            #+#    #+#             */
/*   Updated: 2025/02/02 14:27:30 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_outputs_and_free(t_stacks *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s != NULL)
	{
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s->join_args != NULL)
			free(s->join_args);
		if (s != NULL)
			free(s);
	}
	exit(1);
}

static void	join_args(int argc, char **argv, t_stacks *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	s->join_args = strdup(tmp);
	if (s->join_args == NULL)
		error_outputs_and_free(s, "Error\n");
	if (tmp)
		free(tmp);
}

int	main(int argc, char **argv)
{
	t_stacks	*s;

	s = malloc(sizeof(t_stacks));
	if (!s)
	{
		write(2, "Memory allocation failed\n", 25);
		return (1);
	}
	join_args(argc, argv, s);
	initialize_stacks(argc, argv, s);
	atoi_numbers(s);
	check_numbers(s, 0);
	create_index(s);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	if (s->a_size == 3)
		sort_three_elements(s);
	if (s->a_size == 4 || s->a_size == 5)
		sort_four_five_elements(s);
	if (s->a_size >= 6)
	{
		radix_sort(s);
	}
	return (0);
}
