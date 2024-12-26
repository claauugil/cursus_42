/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-23 16:21:25 by cgil              #+#    #+#             */
/*   Updated: 2024-12-23 16:21:25 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->top == NULL)
		return ; // si no hay nada en b 
	node = b->top;
	b->top = node->next;
	if (b->top != NULL)// si todavia hay nodos en b
		b->top->prev = NULL; // el prev de el nuevo nodo top es NULL
	else
		b->bottom = NULL; // se actualiza solo si la pila queda vacia
	node->next = a->top;
	if (a->top != NULL)
		a->top->prev = node; // el prev del top de a apunta al nodo que sera el  nuevo top
	else
		a->bottom = node; // si es el unico nodo en a
	a->top = node; // actualizo el top de a
	node->prev = NULL; // como es el primero su prev es NULL
	a->size++;
	b->size--;
	write(1 ,"pa\n", 3);
}
