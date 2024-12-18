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

int	search_dups(t_stack *stack)
{
	t_node	*actual;
	t_node	*rest;

	actual = stack->top;
	while (actual != NULL)
	{
		rest = actual->next;
		while (rest != NULL)
		{
			if (actual->value == rest->value)
				return (1);
			rest = rest->next;
		}
		actual = actual->next;
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
			return (0); // si es un caracter distinto de espacios
		str++;
	}
	return (1);
}
int int_range(char *str)
{
	if(*str == '-')
	{
		if (ft_strlen(str) > 11 || (ft_strlen(str) == 11
			&& ft_strncmp(str, "-2147483648", 11) > 0))
				return (0); // si esta fuera del rango
		else
		{
			if (ft_strlen(str) > 10 || (ft_strlen(str) == 10
				 && ft_strncmp(str, "2147483647", 10)> 0))
				 return (0); // si esta fuera del rango
		}
	}
	return (1); // si esta dentro del rango
}
