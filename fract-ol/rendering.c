/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:28:51 by claudia           #+#    #+#             */
/*   Updated: 2025/01/16 16:32:27 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// busca todos los pixels y chequea si estan en el mandelbrot set

static void	my_pixel_put()
{
	
}
void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex_n	z;
	t_complex_n	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
    //pixel coordinates scaled
	c.x = maping(x, -2, +2, WIDTH);
	c.y = maping(y, +2, -2, HEIGHT);
    // how many times to iterate z² + c  to see if the 
        //point scaped
	while (i < fractal->iterations_def)
	{
        // z = z² + c
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->scape_value) // the value scaped 
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_def); // kmk
			my_pixel_put();
			return ;
		}
	}
}

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
}
