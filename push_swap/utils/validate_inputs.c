/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 16:41:22 by cgil              #+#    #+#             */
/*   Updated: 2024-12-17 16:41:22 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_input(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while(str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return(0);
		i++;
	}
	return (1);
}
int	many_inputs(int ac, char *av[])
{

}
int	validate_input(int ac, char *av[]) // solo retorna 0 si da error
{
	if (ac == 1)
		return(0); //error no suficiente input
	if (ac == 2)
		return(single_input(av[1]));
	return (many_inputs(ac, av));
}
