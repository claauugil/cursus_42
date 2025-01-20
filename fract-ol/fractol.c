/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:17:06 by cgil              #+#    #+#             */
/*   Updated: 2025/01/17 17:51:26 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)
		|| ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		fractal.julia_x = ft_atodbl(av[2]);
		fractal.julia_x = ft_atodbl(av[3]);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		print_error();
	}
}*/

int	main(int ac, char **av)
{
	t_fractal	fractal;


	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)
		|| 4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = ft_atodbl(av[2]);
			fractal.julia_y = ft_atodbl(av[3]);
		}
		//TL;DR
		//Prompt correct, kick off the application
		//1)
		fractal_init(&fractal);
		//2)
		fractal_render(&fractal);
		//3)
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		print_error();
	}
}
