/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:58:59 by claudia           #+#    #+#             */
/*   Updated: 2025/01/18 18:38:21 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//ESC o x en pantalla 
int   close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_new_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

int key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        close_handler(fractal);
    else if (keysym == XK_Left)
        fractal->shift_x += 0.5;
    else if (keysym == XK_Right)
        fractal->shift_x -= 0.5;
    else if (keysym == XK_Up)
        fractal->shift_y += 0.5;
    else if (keysym == XK_Down)
        fractal->shift_y -= 0.5;
    /*else if (keysym == XK_plus)
        fractal->iterations_def += 10;
    else if (keysym == XK_minus)
        fractal->iterations_def -= 10;*/
    //refresh new image
    fractal_render(fractal);
    return (0);
}