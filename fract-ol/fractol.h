/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:46:05 by cgil              #+#    #+#             */
/*   Updated: 2025/01/18 18:24:56 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define WIDTH	800
# define HEIGHT	800

#ifndef COLORS_H
#define COLORS_H

#define WHITE 0xFFFFFF
#define BLUE 0x3E00FF
#define ORANGE 0x180161
#define PINK  0xEB3678
#define DARK_PINK  0xC71585
#define DARK_PURPLE 0x180161
#define PURPLE 0xAE00FB
#define PINKY 0xD91656
#define YELLOW 0xFFF078
#define HOLA 0x6528F7
#define CYAN 0xB5FFD9

#endif // COLORS_H

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
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
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
double		mapping(double unscaled_num, double new_min,
				double new_max, double old_min, double old_max);
void		fractal_render(t_fractal *fractal);
t_complex_n	sum_complex(t_complex_n z1, t_complex_n z2);
t_complex_n	square_complex(t_complex_n z);
int 		key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int 		mouse_handler(int button, int x, int y, t_fractal *fractal);
double		ft_atodbl(char *s);
int			tracking_julia(int x, int y, t_fractal *fractal);


#endif
