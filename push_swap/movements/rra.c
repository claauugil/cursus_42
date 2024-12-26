/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:56:17 by claudia           #+#    #+#             */
/*   Updated: 2024/12/26 18:49:38 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ultimo elemento va al primero

void    rra(t_stack *a)
{
    t_node  *node;
    if (!a->top || a->top == a->bottom)
        return ;
    node = a->bottom;
    a->bottom = node->prev;
    a->bottom->next = NULL;
    node->prev = NULL; // lo desvincula de la lista
    node->next = a->top; // actualiza el puntero para que apunte al antiguo top
    a->top->prev = node; // actualiza puntero 
    a->top = node; // cambia el top
    write(1, "rra\n", 4);
}