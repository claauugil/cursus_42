/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:17:06 by cgil              #+#    #+#             */
/*   Updated: 2025/01/15 18:23:02 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)
		|| ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		//fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		print_error();
	}
}
