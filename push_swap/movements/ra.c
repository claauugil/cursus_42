/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:30:19 by claudia           #+#    #+#             */
/*   Updated: 2024/12/26 18:35:34 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack *a)
{
    t_node  *node;
    
    if (!a->top || a->top == a->bottom)
        return ; // si esta vacio o si hay un solo numero
    node = a->top;
    a->top = node->next;
    a->top->prev = NULL; // queda como primero
    a->bottom->next = node; // pone node de ultimo
    node->prev = a->bottom; // el ultimo apunta a el
    node->next = NULL; // final
    a->bottom = node; // 
    write(1, "ra\n", 3);
}