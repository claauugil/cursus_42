/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:54:27 by cgil              #+#    #+#             */
/*   Updated: 2025/01/17 19:09:14 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->scape_value = 4;
	fractal->iterations_def = 42;
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_new_window,
			 KeyPress, 
			 KeyPressMask, 
			 key_handler, 
			 fractal);
	mlx_hook(fractal->mlx_new_window,
			 ButtonPress, 
			 ButtonPressMask, 
			 mouse_handler, 
			 fractal);
	mlx_hook(fractal->mlx_new_window,
			 DestroyNotify, 
			 StructureNotifyMask, 
			 close_handler, 
			 fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_new_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (mlx_new_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_new_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
