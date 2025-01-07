/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:18:14 by cgil              #+#    #+#             */
/*   Updated: 2024/12/26 16:29:55 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
