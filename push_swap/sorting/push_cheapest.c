/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:40:55 by cgil              #+#    #+#             */
/*   Updated: 2025/01/08 16:01:46 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_f_t(t_stack *from, int *depth)
{
	if (*depth > 0)
	{
		ra(from);
		(*depth)--;
	}
	else if (*depth < 0)
	{
		rra(from);
		(*depth)++;
	}
}

void	rotate_tgt_to(t_stack *to, int *depth)
{
	if (*depth > 0)
	{
		rb(to);
		(*depth)--;
	}
	else if (*depth < 0)
	{
		rrb(to);
		(*depth)++;
	}
}

void	rotates(t_stack *from, t_stack *to, int *val_depth, int *tar_depth)
{
	if (*val_depth > 0 && *tar_depth > 0)
	{
		rr(from, to);
		(*val_depth)--;
		(*tar_depth)--;
	}
	else if (*val_depth < 0 && *tar_depth < 0)
	{
		rrr(from, to);
		(*val_depth)++;
		(*tar_depth)++;
	}
}

void	rotate_each(t_stack *from, int *val_depth, t_stack *to, int *tar_depth)
{
	if (*val_depth != 0)
        rotate_f_t(from, val_depth);
    if (*tar_depth != 0)
        rotate_tgt_to(to, tar_depth);
}

int	push_cheapest(t_stack *from, t_stack *to, int val)
{
	int	val_depth;
	int	target;
	int	target_depth;

	val_depth = get_depth(from, val);
	target = get_target(to, val, 1);
	target_depth = get_depth(to, target);
	while (val_depth != 0 || target_depth != 0)
	{
		if ((val_depth > 0 && target_depth > 0) || (val_depth < 0 && target_depth < 0))
			rotates(from, to, &val_depth, &target_depth);
		else
			rotate_each(from, &val_depth, to, &target_depth);
	}
	return (pb(from, to), 0);
}
