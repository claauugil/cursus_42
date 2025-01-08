/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:56:27 by claudia           #+#    #+#             */
/*   Updated: 2025/01/08 12:08:42 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_target(t_stack *search, int n, int up_low)
{
	if (is_biggest(search, n), is_smallest(search, n))
		return (find_biggest(search)); // se busca el mas grande
	else if (up_low) // si es distinto de 0
		return (find_near_lower(search, n)); // valor inmediatamente inferior
	else if (!up_low) // si es cero
		return (find_near_upper(search, n)); // valor inmediatamente superior
	else
		return (INT_MIN); // error
}

int	find_near_lower(t_stack *search, int n)
{
	int		dif;
	int		target;
	t_node	*actual;

	if (!search->top)
		return (INT_MIN);
	dif = INT_MAX;
	target = INT_MIN;
	actual = search->top;
	while (actual)
	{
		if (n - actual->value < dif && n - actual->value > 0)
		{
			dif = n - actual->value;
			target = actual->value;
		}
		actual = actual->next;
	}
	return (target);
}

int	find_near_upper(t_stack *to_search, int target)
{
	t_node	*actual;
	int		near_value; // valor mas cercano encontrado que es mayor que target
	int		near_dif; // diferencia minima entre los valores mayores que el objetivo
	int		dif; // diferencia temporal entre el valor actual del nodo y del objetivo

	if (!to_search || !to_search->top)
		return (INT_MIN);
	actual = to_search->top;
	near_value = INT_MIN;
	near_dif = INT_MAX;
	if (is_biggest(to_search, target))
		return (INT_MAX);
	while (actual)
	{
		dif = actual->value - target;
		if (dif > 0 && dif < near_dif)
		{
			near_dif = dif;
			near_value = actual->value;
		}
		actual = actual->next;
	}
	return (near_value);
}