/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:28:46 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 18:08:05 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	t_node	*node;
	t_node	*sec_node;

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
	sec_node = b->top;
	b->top = sec_node->next;
	b->top->prev = NULL;
	b->bottom->next = sec_node;
	sec_node->prev = b->bottom;
	sec_node->next = NULL;
	b->bottom = sec_node;
	write(1, "rr\n", 3);
}
