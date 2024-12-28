/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-28 10:46:24 by cgil              #+#    #+#             */
/*   Updated: 2024-12-28 10:46:24 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  recorre todos los nodos de b
// para cada uno, determina su posición correcta en a

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

	to_move = INT_MIN; // cualquier numero a comparar será reemplazado por lo que devuelva cheapest
	if (a->size == 2)
	{
		sort_two(a);
		return ;
	}
	if (a->size >= 4)
		pb(a, b);
	if (a->size >= 5)
		pb(a, b);
	while (a->size > 3) // mueve el nodo mas barato hasta que queden solo 3 en a
	{
		to_move = find_cheapest(a, b); // consigue el mas barato de a
		push_cheapest(a, b, to_move); // mueve el nodo mas barato a b
	}
	sort_three(a);
	if (b->size != 0)
	{
		push_back(b, a);
		bring_min_to_top(a);
	}
	return ;
}
