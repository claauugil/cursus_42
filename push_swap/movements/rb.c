/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:14 by claudia           #+#    #+#             */
/*   Updated: 2024/12/26 17:44:32 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rb(t_stack *b)
{
    t_node  *node;

    if (!b->top || b->top == b->bottom)
        return ;
    node = b->top;
    b->top = node->next;
    b->top->prev = NULL;
    b->bottom->next = node;
    node->prev = b->bottom;
    node->next = NULL;
    b->bottom = node;
    write(1, "rb\n", 3);
}