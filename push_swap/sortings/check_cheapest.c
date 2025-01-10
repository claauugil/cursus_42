/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:19:49 by claudia           #+#    #+#             */
/*   Updated: 2025/01/10 13:03:05 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	calculate_combined_moves(int f_depth, int target_depth)
{
	if ((f_depth > 0 && target_depth > 0) || (f_depth < 0 && target_depth < 0))
		return (max(ft_abs(f_depth), ft_abs(target_depth)));
	return (ft_abs(f_depth) + ft_abs(target_depth));
}

int	get_combined_moves(t_stack *from, t_stack *to, int value)
{
	int	f_depth;
	int	target;
	int	target_depth;

	f_depth = get_depth(from, value);
	target = get_target(to, value);
	target_depth = get_depth(to, target);
	return (calculate_combined_moves(f_depth, target_depth));
}

void	update_cheapest(int *actual_moves, int combined_moves,
		int *cheapest_value,
	int value)
{
	if (combined_moves < *actual_moves)
	{
		*actual_moves = combined_moves;
		*cheapest_value = value;
	}
}

int	check_cheapest(t_stack *from, t_stack *to)
{
	t_node	*actual;
	int		actual_moves;
	int		cheapest_val;
	int		combined_moves;

	actual = from->top;
	actual_moves = INT_MAX;
	cheapest_val = INT_MIN;
	while (actual)
	{
		combined_moves = get_combined_moves(from, to, actual->val);
		update_cheapest(&actual_moves, combined_moves, &cheapest_val,
			actual->val);
		actual = actual->next;
	}
	return (cheapest_val);
}
