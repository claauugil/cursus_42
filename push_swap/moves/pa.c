/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:25:34 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 18:10:00 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->top == NULL)
		return ;
	node = b->top;
	b->top = node->next;
	if (b->top != NULL)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	node->next = a->top;
	if (a->top != NULL)
		a->top->prev = node;
	else
		a->bottom = node;
	a->top = node;
	node->prev = NULL;
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}
