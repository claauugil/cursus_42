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
