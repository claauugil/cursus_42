/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:30:19 by claudia           #+#    #+#             */
/*   Updated: 2025/01/08 11:55:16 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	t_node	*node;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->top;
	a->top = node->next;
	a->top->prev = NULL;
	a->bottom->next = node;
	node->prev = a->bottom;
	node->next = NULL;
	a->bottom = node;
	write(1, "ra\n", 3);
}