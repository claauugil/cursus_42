/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 15:22:10 by cgil              #+#    #+#             */
/*   Updated: 2024-12-27 15:22:10 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//busca un nodo en la pila y calcula su profundidad la profundidad

int	get_depth(t_stack *in_stack, int val)
{
	int		i;
	t_node	*actual;

	i = 0;
	actual = in_stack->top;
	while (actual)
	{
		if (actual->value == val) // si encuentra un nodo igual al que busca
		{
			if (i <= in_stack->size / 2) // si esta en la mitad superior de la pila
				return (i);
			else
				return (i - in_stack->size); // si esta en la mitad inferior de la pila
		}
		i++;
		actual = actual->next;
	}
}

void	bring_to_top(t_stack *a, int target)
{
	int		depth;

	depth = get_depth(a, target);
	while (depth != 0)
	{
		if (depth < 0)
		{
			rra(a);
			depth++;
		}
		if (depth > 0)
		{
			ra(a);
			depth--;
		}
	}
}

//por si el minimo no queda de primero
void	bring_min_to_top(t_stack *in_stack)
{
	int	min_value;

	if (!in_stack || !in_stack->top)
		return ;
	min_value = find_smallest(in_stack);
	bring_to_top(in_stack, min_value);
}

void	sort_two(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return ;
	if (stack->top->value > stack->top->next->value)
		sa(stack);
}

int	is_sorted(t_stack *stack)
{
	t_node	*actual;

	if (!stack || !stack->top)
		return (1);
	actual = stack->top;
	while (actual && actual->next)
	{
		if (actual->value > actual->next->value)
			return (0);
		actual = actual->next;
	}
	return (1);
}
