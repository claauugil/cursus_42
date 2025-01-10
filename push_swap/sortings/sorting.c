/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:23:33 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 18:05:52 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack *b, t_stack *a)
{
	t_node	*actual;
	int		target;

	actual = b->top;
	while (actual)
	{
		if (b->top == NULL)
			break ;
		actual = b->top;
		target = find_near_upper(a, actual->val);
		if (target == INT_MAX)
			target = find_smallest(a);
		bring_to_top(a, target);
		pa(a, b);
		actual = actual->next;
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int	to_move;

	to_move = INT_MIN;
	if (a->size == 2)
	{
		sort_two(a);
		return ;
	}
	if (a->size >= 4)
		pb(a, b);
	if (a->size >= 5)
		pb(a, b);
	while (a->size > 3)
	{
		to_move = check_cheapest(a, b);
		push_cheapest(a, b, to_move);
	}
	sort_three(a);
	if (b->size != 0)
	{
		push_back(b, a);
		bring_min_to_top(a);
	}
	return ;
}
