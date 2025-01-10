/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:22:52 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 18:05:44 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	largest_at_top(t_stack *a)
{
	if (a->top->next->val < a->top->next->next->val)
		ra(a);
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

	first = a->top->val;
	second = a->top->next->val;
	third = a->top->next->next->val;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && first > third)
		largest_at_top(a);
	else if (first < second && first > third)
		rra(a);
	else if (first < second && second > third)
		smallest_in_middle(a);
}
