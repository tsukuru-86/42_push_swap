/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:42:26 by tsukuru           #+#    #+#             */
/*   Updated: 2025/02/02 14:46:21 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_elements(t_stacks *s)
{
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2])
		rotate(s->a, s->a_size, "up", "a");
	else if (s->a[1] > s->a[0] && s->a[1] > s->a[2])
		rotate(s->a, s->a_size, "down", "a");
	if (s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
}

void	sort_four_five_elements(t_stacks *s)
{
	while (s->b_size <= 1)
	{
		while (s->a[0] > s->a[1] || (s->a_size > 2 && s->a[0] > s->a[2]) ||
				(s->a_size > 3 && s->a[0] > s->a[3]) ||
				(s->a_size > 4 && s->a[0] > s->a[4]))
		{
			rotate(s->a, s->a_size, "up", "a");
		}
		push("pb", s);
	}
	if (s->b[0] < s->b[1])
		swap("sb", s->b, s->b_size);
	if (s->a_size == 2)
	{
		if (s->a[0] > s->a[1])
			swap("sa", s->a, s->a_size);
	}
	if (s->a_size == 3)
		sort_three_elements(s);
	push("pa", s);
	push("pa", s);
}

// アップグレードバージョン　これで完成とも言える
void radix_sort(t_stacks *s)
{
    int i, j;
    int max_bits;
    int size;
    int max_val;

    /* 最大値は正規化済みなので s->a_size - 1 */
    max_val = s->a_size - 1;
    max_bits = 0;
    while ((max_val >> max_bits) != 0)
        max_bits++;

    for (j = 0; j < max_bits; j++)
    {
        size = s->a_size;
        for (i = 0; i < size; i++)
        {
            if (((s->a[0] >> j) & 1) == 1)
                rotate(s->a, s->a_size, "up", "a");
            else
                push("pb", s);
        }
        while (s->b_size > 0)
            push("pa", s);
    }
}

// //元祖　サンプル元と同じ
// static void	radix_sort_stack_b(t_stacks *s, int b_size, int bit_size, int j)
// {
// 	while (b_size-- && j <= bit_size && !is_array_sorted(s))
// 	{
// 		if (((s->b[0] >> j) & 1) == 0)
// 			rotate(s->b, s->b_size, "up", "b");
// 		else
// 			push("pa", s);
// 	}
// 	if (is_array_sorted(s))
// 		while (s->b_size != 0)
// 			push("pa", s);
// }

// void	radix_sort(t_stacks *s)
// {
// 	int	j;
// 	int	bit_size;
// 	int	size;

// 	bit_size = 0;
// 	size = s->a_size;
// 	while (size > 1 && ++bit_size)
// 		size /= 2;
// 	j = -1;
// 	while (++j <= bit_size)
// 	{
// 		size = s->a_size;
// 		while (size-- && !is_array_sorted(s))
// 		{
// 			if (((s->a[0] >> j) & 1) == 0)
// 				push("pb", s);
// 			else
// 				rotate(s->a, s->a_size, "up", "a");
// 		}
// 		radix_sort_stack_b(s, s->b_size, bit_size, j + 1);
// 	}
// 	while (s->b_size != 0)
// 		push("pa", s);
// }