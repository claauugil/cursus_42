/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:46:24 by cgil              #+#    #+#             */
/*   Updated: 2025/01/03 17:52:35 by claudia          ###   ########.fr       */
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
		target = find_closest_upper(a, actual->value);
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
