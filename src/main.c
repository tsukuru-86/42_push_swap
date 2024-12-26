/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:39:25 by tsukuru           #+#    #+#             */
/*   Updated: 2024/12/26 17:42:18 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//エラーの出力制御関数
void error_outputs_and_free(t_stacks *s, char *msg)
{
    if (msg)
        write(2, msg, ft_strlen(msg));

    //ここで後でFreeも行う
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

// コマンドライン引数に入力した文字配列を一つの文字列に変換
static void join_args(int argc, char **argv, t_stacks *s)
{
    char *tmp;
    char *tmp2;
    int i;

    i = 0;
    tmp2 = ft_strdup("");
    while (++i < argc && argv[i] != NULL)
    {
        tmp = ft_strjoin(tmp2, argv[i]);
        if (tmp2)
            free(tmp2);
        if (i != argc -1)
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

int main(int argc, char**argv)
{
    t_stacks *s = malloc(sizeof(t_stacks)); // 構造体のポインタを作成
    if (!s)
    {
        write(2, "Memory allocation failed\n", 25);
        return (1);
    }    //エラー処理
    
    join_args(argc, argv, s);//文字列を"77 6 7878 8 23 7"のような一つの文字列に
    initialize_stacks(argc, argv, s);//stackAとBを確保
    atoi_numbers(s);//文字列を　77 6 7878 8 23 7のような数値に変換しそれぞれ挿入
    //indexを作成
    //とりあえずソートするアルゴリズム書いてみる
        //文字列の数によって条件分岐？
        //各条件ごとのソート
    
    int i = 0;
    while (i < s->a_size)
    {
        printf("%d\n", s->a[i]);
        i++;
    }
    
    free(s->a);
    free(s->b);
    free(s);

    return 0;
}