/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-28 12:26:17 by cgil              #+#    #+#             */
/*   Updated: 2024-12-28 12:26:17 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	largest_at_top(t_stack *a)
{
	if (a->top->next->value < a->top->next->next->value)
		ra(a); // si el segundo es mayor que el tercero
	else
	{
		sa(a);
		rra(a);
	}
}

void	smallest_in_middle(t_stack *a)
{
	sa(a);
	ra(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(a); // si el mayor esta de ultimo y los dos primeros desordenados
	else if (first > second && first > third) // si el mayor esta de primero
		largest_at_top(a);
	else if (first < second && first > third)
		rra(a); // si el mas grande esta en el medio
	else if (first < second && second > third)
		smallest_in_middle(a);
}
