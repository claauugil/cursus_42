/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:56:27 by claudia           #+#    #+#             */
/*   Updated: 2025/01/03 17:58:35 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_stack *search, int n, int up_low)
{
	// si es el mas chico o el mas grande
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
	int	dif;
	int	target;
	t_node	*actual;

	if (!search->top)
		return (INT_MIN);
	dif = INT_MAX; // diferencia minima enontrada entre n y un valor de a pila, siempre va a encontrar algo menor
	target = INT_MIN; // el nodo mas cercano inferior a n
	actual = search->top;
	while (actual)
	{  //que n sea mayor que actual value
		if (n - actual->value < dif && n - actual->value > 0)
		{
			dif = n - actual->value;
			target = actual->value;
		}
		actual = actual->next;
	}
	return (target);
}
