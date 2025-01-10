/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:28:18 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 18:08:02 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *b)
{
	t_node	*node;

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
