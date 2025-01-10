/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_big_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:59 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 17:59:02 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

int	is_biggest(t_stack *in_stack, int n)
{
	t_node	*actual;

	if (!in_stack->top)
		return (INT_MIN);
	actual = in_stack->top;
	while (actual)
	{
		if (n < actual->val)
			return (0);
		actual = actual->next;
	}
	return (1);
}

int	is_smallest(t_stack *in_stack, int n)
{
	t_node	*actual;

	if (!in_stack->top)
		return (INT_MIN);
	actual = in_stack->top;
	while (actual)
	{
		if (n > actual->val)
			return (0);
		actual = actual->next;
	}
	return (1);
}

int	find_biggest(t_stack *to_find)
{
	t_node	*actual;
	int		max;

	if (!to_find->top)
		return (INT_MIN);
	actual = to_find->top;
	max = actual->val;
	while (actual)
	{
		if (max < actual->val)
			max = actual->val;
		actual = actual->next;
	}
	return (max);
}

int	find_smallest(t_stack *to_find)
{
	t_node	*actual;
	int		min;

	if (!to_find->top)
		return (INT_MIN);
	actual = to_find->top;
	min = actual->val;
	while (actual)
	{
		if (min > actual->val)
			min = actual->val;
		actual = actual->next;
	}
	return (min);
}
