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

#include "../push_swap.h"

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
