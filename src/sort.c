/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:42:26 by tsukuru           #+#    #+#             */
/*   Updated: 2025/01/31 20:24:41 by tsukuru          ###   ########.fr       */
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
// void radix_sort(t_stacks *s)
// {
//     int i, j;
//     int max_bits;
//     int size;
//     int max_val;

//     /* 最大値は正規化済みなので s->a_size - 1 */
//     max_val = s->a_size - 1;
//     max_bits = 0;
//     while ((max_val >> max_bits) != 0)
//         max_bits++;

//     for (j = 0; j < max_bits; j++)
//     {
//         size = s->a_size;
//         for (i = 0; i < size; i++)
//         {
//             if (((s->a[0] >> j) & 1) == 1)
//                 rotate(s->a, s->a_size, "up", "a");
//             else
//                 push("pb", s);
//         }
//         while (s->b_size > 0)
//             push("pa", s);
//     }
// }


//元祖　サンプル元と同じ
static void	radix_sort_stack_b(t_stacks *s, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_array_sorted(s))
	{
		if (((s->b[0] >> j) & 1) == 0)
			rotate(s->b, s->b_size, "up", "b");
		else
			push("pa", s);
	}
	if (is_array_sorted(s))
		while (s->b_size != 0)
			push("pa", s);
}

void	radix_sort(t_stacks *s)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = s->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = s->a_size;
		while (size-- && !is_array_sorted(s))
		{
			if (((s->a[0] >> j) & 1) == 0)
				push("pb", s);
			else
				rotate(s->a, s->a_size, "up", "a");
		}
		radix_sort_stack_b(s, s->b_size, bit_size, j + 1);
	}
	while (s->b_size != 0)
		push("pa", s);
}












// /* --- スタックの中で最大値の位置を返す --- */
// int find_max_index(int *stack, int size)
// {
//     int max = stack[0];
//     int index = 0;
//     int i;
//     for (i = 1; i < size; i++)
//     {
//         if (stack[i] > max)
//         {
//             max = stack[i];
//             index = i;
//         }
//     }
//     return index;
// }

// /* --- チャンクサイズを決定する（例） --- */
// int determine_chunk_size(int total_elements)
// {
//     if (total_elements <= 100)
//         return 20;
//     else if (total_elements <= 500)
//         return 40;
//     else
//         return 50;
// }

// /* 
//  * chunk_sort: 
//  *   1) 要素をチャンクごとにBに押し込む
//  *   2) 最後にBからAへ戻し、Aを完全ソート状態にする
//  */
// void chunk_sort(t_stacks *s)
// {
//     int chunk_size      = determine_chunk_size(s->a_size);
//     int total_chunks    = (s->a_size + chunk_size - 1) / chunk_size;
//     int current_chunk   = 0;

//     /*
//      * 【フェーズ1】A→Bへ
//      *   各チャンクごとに、「そのチャンクに属する要素を全部Bに移す」までループ
//      *   ここでは「Aの先頭を確認して、チャンク範囲にあればpb、なければra」を繰り返し、
//      *   該当要素を取りこぼさないようにする。
//      */
//     while (current_chunk < total_chunks)
//     {
//         // 現在のチャンクが扱う値の範囲（例：0～19, 20～39, ...）
//         int lower_bound = current_chunk * chunk_size;
//         int upper_bound = (current_chunk + 1) * chunk_size - 1;

//         while (1)
//         {
//             // まだ A の中に、現在のチャンクに属する要素が残っているかチェック
//             int found_in_chunk = 0;
//             for (int i = 0; i < s->a_size; i++)
//             {
//                 if (s->a[i] >= lower_bound && s->a[i] <= upper_bound)
//                 {
//                     found_in_chunk = 1;
//                     break;
//                 }
//             }
//             // もしもう見つからないなら、このチャンクは完了
//             if (!found_in_chunk)
//                 break;

//             // Aの先頭要素がチャンク範囲に入っていれば B へpush
//             if (s->a[0] >= lower_bound && s->a[0] <= upper_bound)
//             {
//                 push("pb", s);
//             }
//             else
//             {
//                 // 該当でなければ A を回転し、次の要素を先頭に持ってくる
//                 rotate(s->a, s->a_size, "up", "a");
//             }
//         }
//         // 次のチャンクへ
//         current_chunk++;
//     }

//     /*
//      * 【フェーズ2】B→Aへ
//      *   Bにある要素を、最大値を順にAへpushしていくことで、Aを昇順に並べる。
//      *   （Bの先頭に最大値がくるよう回転してから pa）
//      */
//     while (s->b_size > 0)
//     {
//         int max_idx = find_max_index(s->b, s->b_size);

//         // 最大値が B のどの位置にいるかで回転方向を決定
//         if (max_idx <= s->b_size / 2)
//         {
//             // 上半分にあれば、上回転で先頭へ
//             while (max_idx-- > 0)
//                 rotate(s->b, s->b_size, "up", "b");
//         }
//         else
//         {
//             // 下半分にあれば、下回転で先頭へ
//             int moves = s->b_size - max_idx;
//             while (moves-- > 0)
//                 rotate(s->b, s->b_size, "down", "b");
//         }
//         // 先頭へ持ってきた最大値を A に移動
//         push("pa", s);
//     }
// }
