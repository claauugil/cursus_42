/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:56:13 by cgil              #+#    #+#             */
/*   Updated: 2025/01/08 16:24:17 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*node;
	t_node	*sec_node;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->bottom;
	a->bottom = node->prev;
	a->bottom->next = NULL;
	node->prev = NULL;
	node->next = a->top;
	a->top->prev = node;
	a->top = node;
	if (!b->top || b->top == b->bottom)
		return ;
	sec_node = b->bottom;
	b->bottom = sec_node->prev;
	b->bottom->next = NULL;
	sec_node->prev = NULL;
	sec_node->next = b->top;
	b->top->prev = sec_node;
	b->top = sec_node;
	write(1, "rrr\n", 4);
}