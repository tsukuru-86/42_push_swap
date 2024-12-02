/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:37:05 by tsukuru           #+#    #+#             */
/*   Updated: 2024/12/02 16:59:22 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <assert.h>


void swap(char *str, int *array, int size)
{
    int tmp;

    if (size <= 0)
        return ;
    
    tmp = array[0];
    array[0] = array[1];
    array[1] = tmp;
    ft_putendl_fd(str, 1);
}

void push(char *str, t_stacks*s)
{
    int tmp;
    if (ft_strncmp(str, "pa", 3)== 0)
    {
        if (s->b_size <= 0)
            return ;
        tmp = s->b[0];
        ft_memmove(s->a + 1, s->a, sizeof(int) * s->a_size);
        s->a[0] = tmp;
        s->b_size--;
        ft_memmove(s->b, s->b + 1, sizeof(int) * s->b_size);
        s->a_size++;
    }else
    {
        if (ft_strncmp)
    }
}