/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 00:00:00 by tsukuru           #+#    #+#             */
/*   Updated: 2026/08/29 00:00:00 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	same_text(const char *left, const char *right)
{
	while (*left && *left == *right)
	{
		left++;
		right++;
	}
	return (*left == *right);
}

static int	operation_from_line(char *line)
{
	const char	*names[11];
	int			operation;

	names[0] = "sa";
	names[1] = "sb";
	names[2] = "ss";
	names[3] = "pa";
	names[4] = "pb";
	names[5] = "ra";
	names[6] = "rb";
	names[7] = "rr";
	names[8] = "rra";
	names[9] = "rrb";
	names[10] = "rrr";
	operation = -1;
	while (++operation < 11)
		if (same_text(line, names[operation]))
			return (operation);
	return (-1);
}

static int	read_operation(int *operation)
{
	char	line[4];
	char	character;
	int		length;
	ssize_t	bytes;

	length = 0;
	bytes = read(STDIN_FILENO, &character, 1);
	while (bytes > 0 && character != '\n')
	{
		if (length == 3)
			return (-1);
		line[length++] = character;
		bytes = read(STDIN_FILENO, &character, 1);
	}
	if (bytes < 0)
		return (-1);
	if (bytes == 0 && length == 0)
		return (0);
	line[length] = '\0';
	*operation = operation_from_line(line);
	if (*operation < 0)
		return (-1);
	return (1);
}

static int	checker_error(t_stacks *stacks)
{
	ps_free(stacks);
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			operation;
	int			status;

	if (argc == 1)
		return (0);
	if (!ps_parse_arguments(argc, argv, &stacks))
		return (write(2, "Error\n", 6), 1);
	if (ps_has_duplicates(&stacks.a))
		return (checker_error(&stacks));
	status = read_operation(&operation);
	while (status > 0)
	{
		ps_execute(&stacks, operation, 0);
		status = read_operation(&operation);
	}
	if (status < 0)
		return (checker_error(&stacks));
	if (stacks.b.size == 0 && ps_is_sorted(&stacks.a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	ps_free(&stacks);
	return (0);
}
