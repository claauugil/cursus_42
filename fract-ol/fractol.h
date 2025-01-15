/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:46:05 by cgil              #+#    #+#             */
/*   Updated: 2025/01/15 19:16:00 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define WIDTH	800
# define HEIGHT	800

typedef struct s_image
{
	void	*img_ptr; // pointer to image struct
	char	*pixels_ptr; // points to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
}			t_image;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection; //mlx_init
	void	*mlx_new_window; //mlx_new_window
	t_image	img;
	//add hooks members variable
	double	scape_value;
	int		iterations_def; //value tied to image quality
}		t_fractal;

typedef struct s_complex_n
{
	double	x;
	double	y;
}			t_complex_n;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		print_error(void);
void		malloc_error(void);
void		fractal_init(t_fractal *fractal);
double		maping(double unscaled_num, double new_min,
				double new_max, double old_max);
void		fractal_render(t_fractal *fractal);
t_complex_n	sum_complex(t_complex_n z1, t_complex_n z2);
t_complex_n	square_complex(t_complex_n z);

#endif