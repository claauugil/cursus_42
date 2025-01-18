/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:28:51 by claudia           #+#    #+#             */
/*   Updated: 2025/01/17 18:39:29 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// pone un pixel en el buffer de imagenes

static void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
//asigna un color a cada pixel dependiendo de las iteraciones
// que haga y si llega al scape value

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex_n	z;
	t_complex_n	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
    //pixel coordinates scaled
	c.x = mapping(x, -2, +2, 0, WIDTH);
	c.y = mapping(y, +2, -2, 0, HEIGHT);
    // how many times to iterate z² + c  to see if the 
        //point scaped
	while (i < fractal->iterations_def)
	{
        // z = z² + c
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->scape_value) // the value scaped 
		{
			color = mapping(i, BLACK, WHITE, 0, fractal->iterations_def); // kmk
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	// si esta dentro del plano mandelbrot 
	my_pixel_put(x, y, &fractal->img, DARK_PINK);
}
// recorre todos los pixeles de una ventana y calcula el color correspondiente
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,fractal->mlx_new_window, fractal->img.img_ptr, 0, 0);
}
