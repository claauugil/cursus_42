/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_big.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-30 12:09:49 by cgil              #+#    #+#             */
/*   Updated: 2024-12-30 12:09:49 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// verifica si n es el numero mas grande de la pila

int	is_biggest(t_stack *in_stack, int n)
{
	t_node	*actual;

	if (!in_stack->top)
		return (INT_MIN); //  para indicar que la pila esta vacia
	actual = in_stack->top;
	while(actual)
	{
		if (n < actual->value)
			return (0); // si no es el mayor
		actual = actual->next;
	}
	return (1); // retorna 1 si es el mayor
}

int	is_smallest(t_stack *in_stack, int n)
{
	t_node	*actual;

	if (!in_stack->top)
		return (INT_MIN);
	actual = in_stack->top;
	while (actual)
	{
		if (n > actual->value)
			return (0); // si no es el menor
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
	max = actual->value;
	while (actual)
	{
		if (max < actual->value)
			max = actual->value;
		actual = actual->next;
	}
	return (max);
}

int	find_smallest(t_stack *to_find)
{
	t_node	*actual;
	int	min;

	if (!to_find->top)
		return(INT_MIN);
	actual = to_find->top;
	min = actual->value;
	while (actual)
	{
		if (min > actual->value)
			min =actual->value;
		actual = actual->next;
	}
	return (min);
}

int	max(int a, int b)
{
	if (a < b)
		return (a);
	return(b);
}
