/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:17:03 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 18:44:20 by claudia          ###   ########.fr       */
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
			return (0);
	}
	else
	{
		if (len > 10 || (len == 10
				&& ft_strncmp(str, "2147483647", 10) > 0))
			return (0);
	}
	return (1);
}

int	is_numeric_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	many_inputs(int ac, char *av[])
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_numeric_input(av[i]) || !int_range(av[i]))
			return (0);
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
		if (!is_numeric_input(nums[i]) || !int_range(nums[i]))
		{
			free_split(nums);
			return (0);
		}
		i++;
	}
	free_split(nums);
	return (1);
}

int	validate_input(int ac, char *av[])
{
	if (ac == 2)
		return (only_input(av[1]));
	return (many_inputs(ac, av));
}
