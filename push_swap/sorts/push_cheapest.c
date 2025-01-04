/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-04 15:40:55 by cgil              #+#    #+#             */
/*   Updated: 2025-01-04 15:40:55 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_f_t(t_stack *from, int *depth)
{
	if (*depth > 0)
	{
		ra(from);
		(*depth)--;
	}
	else
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
	else
		rrb(to);
		(*depth)++;
}

void	rotates(t_stack *from, t_stack *to, int *val_depth, int *tar_depth)
{
	if (*val_depth > 0 && tar_depth > 0)
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
	
}
