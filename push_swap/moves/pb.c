/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:26:19 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 18:10:20 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (a->top == NULL)
		return ;
	node = a ->top;
	a->top = node->next;
	if (a->top != NULL)
		a->top->prev = NULL;
	else
		a->bottom = NULL;
	node->next = b->top;
	if (b->top != NULL)
		b->top->prev = node;
	else
		b->bottom = node;
	b->top = node;
	node->prev = NULL;
	b->size++;
	a->size--;
	write(1, "pb\n", 3);
}
