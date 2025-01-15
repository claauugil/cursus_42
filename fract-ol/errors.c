/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:48:16 by claudia           #+#    #+#             */
/*   Updated: 2025/01/15 18:34:19 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error(void)
{
	write(2, "check correct arguments to run the program", 43);
	exit(EXIT_FAILURE);
}

void	malloc_error(void)
{
	perror("Error while allocating memory with malloc");
	exit(EXIT_FAILURE);
}
