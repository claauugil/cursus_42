/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:47:56 by claudia           #+#    #+#             */
/*   Updated: 2024/12/26 17:52:19 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rr(t_stack *a, t_stack *b)
{
    t_node  *node;
    t_node  *node2;

    if (!a->top || a->top == a->bottom)
        return ;
    node = a->top;
    a->top = node->next;
    a->top->prev = NULL;
    a->bottom->next = node;
    node->prev = a->bottom;
    node->next = NULL;
    a->bottom = node;
    if (!b->top || b->top == b->bottom)
        return ;
    node = b->top;
    b->top = node->next;
    b->top->prev = NULL;
    b->bottom->next = node;
    node->prev = b->bottom;
    node->next = NULL;
    b->bottom = node;
    write(1, "rr\n", 3);
}