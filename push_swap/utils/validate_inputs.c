/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-19 13:01:51 by cgil              #+#    #+#             */
/*   Updated: 2024-12-19 13:01:51 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_range(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (*str == '-')
	{
		if (len > 11 || (len == 11
				&& ft_strncmp(str, "-2147483648", 11) > 0))
			return (0); // si esta fuera del rango
	}
	else
	{
		if (len > 10 || (len == 10
				&& ft_strncmp(str, "2147483647", 10) > 0))
			return (0);// si esta fuera del rango
	}
	return (1); // si esta dentro del rango
}

int	is_numeric_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0); // input invalido
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i])) // si retorna 0
			return (0);
		i++;
	}
	return (1); // si es valido
}

int	many_inputs(int ac, char *av[])
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_numeric_input(av[i]) || !int_range(av[i])) // si retorna  0
			return (0); // si es invalido
		i++;
	}
	return (1);
}

int	only_input(char *str)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(str, ' ');
	if (!nums)
		return (0);
	while (nums[i])
	{
		if (!is_numeric_input(nums[i]) || !int_range(nums[i])) // si alguna retorna 0
		{
			free_split(i, nums);
			return (0); // invalido
		}
		i++;
	}
	free_split(i, nums);
	return (1); // valido
}

int	validate_input(int ac, char *av[])
{
	if (ac == 2)
		return (only_input(av[1]));
	return (many_inputs(ac, av));
}
