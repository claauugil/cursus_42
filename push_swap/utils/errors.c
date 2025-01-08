/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:40:18 by cgil              #+#    #+#             */
/*   Updated: 2025/01/08 16:04:31 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_dups(t_stack *stack)
{
	t_node	*current;
	t_node	*inner;

	current = stack->top;
	while (current != NULL)
	{
		inner = current->next;
		while (inner != NULL)
		{
			if (current->value == inner->value)
				return (1);
			inner = inner->next;
		}
		current = current->next;
	}
	return (0);
}

int	empty_string(char *str)
{
	if (!str || str[0] == '\0')
		return (1);
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n'
			&& *str != '\v' && *str != '\f' && *str != '\r')
			return (0);
		str++;
	}
	return (1);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/*void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = stack_a ? stack_a->top : NULL;
	current_b = stack_b ? stack_b->top : NULL;
	printf("Stack A (top to bottom)\tStack B (top to bottom)\n");
	printf("-------------------------------------------------\n");
	while (current_a || current_b)
	{
		if (current_a)
		{
			printf("%-20d", current_a->value);
			current_a = current_a->next;
		}
		else
		{
			printf("%-20s", " ");
		}
		if (current_b)
		{
			printf("%d", current_b->value);
			current_b = current_b->next;
		}
		printf("\n");
	}
}*/