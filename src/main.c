/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:27:26 by tkomai            #+#    #+#             */
/*   Updated: 2025/02/07 11:48:59 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	join_args(int argc, char **argv, t_stacks *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	if (!tmp2)
		error_outputs_and_free(s, "Error\n");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = join_args_helper(tmp2, argv[i], s);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			free(tmp);
			if (!tmp2)
				error_outputs_and_free(s, "Error\n");
		}
		else
			tmp2 = tmp;
	}
	s->join_args = ft_strdup(tmp2);
	free(tmp2);
	if (!s->join_args)
		error_outputs_and_free(s, "Error\n");
}

static void	execute_sort(t_stacks *s)
{
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	if (s->a_size == 3)
		sort_three_elements(s);
	if (s->a_size == 4 || s->a_size == 5)
		sort_four_five_elements(s);
	if (s->a_size >= 6)
		radix_sort(s);
}

int	main(int argc, char **argv)
{
	t_stacks	*s;

	if (argc < 2)
		return (0);
	if (argv[1][0] == '"' && argv[1][ft_strlen(argv[1]) - 1] != '"')
	{
		write(2, "Error\n", 6);
		return (1);
	}
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
	execute_sort(s);
	free_stacks(s);
	return (0);
}
