/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:50:25 by tsukuru           #+#    #+#             */
/*   Updated: 2024/12/02 20:23:53 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stacks
{
    int *a;
    int *b;
    int a_size;
    int b_size;
}t_stacks;

#include "../libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

#endif