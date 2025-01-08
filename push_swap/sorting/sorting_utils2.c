/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:26:17 by cgil              #+#    #+#             */
/*   Updated: 2025/01/08 16:14:07 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	largest_at_top(t_stack *a)
{
	if (a->top->next->value < a->top->next->next->value)
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

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
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