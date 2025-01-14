/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 12:17:06 by cgil              #+#    #+#             */
/*   Updated: 2025-01-14 12:17:06 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//mandelbrot no recibe args, julia recibe 2

static void	print_error(void);

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)
			|| ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		print_error();
	}
}

static void	print_error(void)
{
	write(2, "please check correct way to run", 32);
	exit(EXIT_FAILURE);
}
