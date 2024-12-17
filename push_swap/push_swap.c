/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 11:47:48 by cgil              #+#    #+#             */
/*   Updated: 2024-12-17 11:47:48 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
	t_stack *stack_a; //puntero a una pila, no la pila
	t_stack *stack_b;

	if (scan_error(ac, av))
		print_error();
	stack_a = init_stack(); //inicializo stack
	stack_b = init_stack();
	if (!stack_a || !stack_b) // si la funcion devuelve NULL
		print_error();
	process_init_stack(ac, av, stack_a);
	if (if_dups(stack_a)) // duplicados
		print_error();
	if (!is_sorted(stack_a))
		sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
int	scan_error(int ac, char *av[])
{
	int i;

	i = 1;
	if (ac > 1 && empty_string(av[1])) // si la string esta vacia
		return (1);
	if (ac == 1) //si no hay suficientes argumentos
		return (1);
	while (i < ac)
	{
		if (!fits_range(av[i])) // si no esta en el rango de los ints
			return(1);
		i++;
	}
	if (!validate_input(ac, av)) // si retorna 0
		return (1);
	return (0);
}
void print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

