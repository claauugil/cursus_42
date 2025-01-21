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
int close_handler(t_fractal *fractal)
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
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (keysym == XK_Right)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (keysym == XK_Up)
        fractal->shift_y += (0.5 * fractal->zoom);
    else if (keysym == XK_Down)
        fractal->shift_y -= (0.5 * fractal->zoom);
    else if (keysym == XK_plus)
        fractal->iterations_def += 10;
    else if (keysym == XK_minus)
        fractal->iterations_def -= 10;
    fractal_render(fractal);
    return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    if (button == Button4)
        fractal->zoom *= 0.95;
    else if (button == Button5)
        fractal->zoom *= 1.05;
    fractal_render(fractal);
    return (0);
}

int tracking_julia(int x, int y, t_fractal *fractal)
{
    if (!ft_strncmp(fractal->name, "julia", 5))
    {
        fractal->julia_x = (mapping (x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
        fractal->julia_y = (mapping (x, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
        fractal_render(fractal);
    }
    return (0);
}
