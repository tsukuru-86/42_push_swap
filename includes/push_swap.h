/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:50:25 by tsukuru           #+#    #+#             */
/*   Updated: 2025/02/07 12:36:22 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

void		check_numbers(t_stacks *s, int i);
int			is_array_sorted(t_stacks *s);
void		error_outputs_and_free(t_stacks *s, char *msg);
void		atoi_numbers(t_stacks *s);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		rotate(int *array, int size, char *direction, char *list);
void		initialize_stacks(int argc, char **argv, t_stacks *s);
void		create_index(t_stacks *s);
void		sort_three_elements(t_stacks *s);
void		sort_four_five_elements(t_stacks *s);
void		radix_sort(t_stacks *s);
int			count_numbers(char *str, char c);
int			ft_atol(const char *n, t_stacks *s);
char		*join_args_helper(char *tmp2, char *argv_i, t_stacks *s);
void		free_stacks(t_stacks *s);
#endif
