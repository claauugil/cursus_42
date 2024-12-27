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

int	search_dups(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + i;
		while (j < ac)
		{
			if (ft_atoi(av[i] == ft_atoi(av[j])))
				return (1);
			j++;
		}
		i++;
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
