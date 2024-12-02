/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:37:05 by tsukuru           #+#    #+#             */
/*   Updated: 2024/12/02 22:11:47 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdbool.h>

// swap関数
void swap(char *str, int *array, int size)
{
    int tmp;

    if (size <= 0)
        return;
    
    tmp = array[0];
    array[0] = array[1];
    array[1] = tmp;
    ft_putendl_fd(str, 1);
}

// push関数
void push(char *str, t_stacks *s)
{
    int tmp;
    if (ft_strncmp(str, "pa", 3) == 0)
    {
        if (s->b_size <= 0)
            return;
        tmp = s->b[0];
        ft_memmove(s->a + 1, s->a, sizeof(int) * s->a_size);
        s->a[0] = tmp;
        s->b_size--;
        ft_memmove(s->b, s->b + 1, sizeof(int) * s->b_size);
        s->a_size++;
    }
    else if (ft_strncmp(str, "pb", 3) == 0)
    {   
        if (s->a_size <= 0)
            return;
        tmp = s->a[0];
        ft_memmove(s->b + 1, s->b, sizeof(int) * s->b_size);
        s->b[0] = tmp;
        s->a_size--;
        ft_memmove(s->a, s->a + 1, sizeof(int) * s->a_size);
        s->b_size++;
    }
    ft_putendl_fd(str, 1);
}

// rotate関数
void rotate(int *array, int size, char *direction, char *list)
{
    int tmp;

    if (size <= 0)
        return;
    if (ft_strncmp(direction, "up", 5) == 0)
    {
        tmp = array[0];
        ft_memmove(array, array + 1, sizeof(int) * (size - 1));
        array[size - 1] = tmp;
        write(1, "r", 1);
    }
    else if (ft_strncmp(direction, "down", 5) == 0)
    {
        tmp = array[size - 1];
        ft_memmove(array + 1, array, sizeof(int) * (size - 1));
        array[0] = tmp;
        write(1, "rr", 2);
    }
    ft_putendl_fd(list, 1);
}