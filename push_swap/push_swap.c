/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:06:06 by claudia           #+#    #+#             */
/*   Updated: 2025/01/10 12:54:52 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	scan_error(int ac, char *av[])
{
	if (ac > 1 && empty_string(av[1]))
		return (1);
	if (ac == 1)
		return (1);
	if (!validate_input(ac, av))
		return (1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (scan_error(ac, av))
		print_error_exit(NULL, NULL);
	stack_a = create_stack();
	stack_b = create_stack();
	if (!stack_a || !stack_b)
		print_error_exit(stack_a, stack_a);
	init_stack(ac, av, stack_a);
	if (search_dups(stack_a))
		print_error_exit(stack_a, stack_b);
	if (!is_sorted(stack_a))
		sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
