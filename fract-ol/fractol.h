/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 15:46:05 by cgil              #+#    #+#             */
/*   Updated: 2025-01-13 15:46:05 by cgil             ###   ########.fr       */
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

//IMAGE: pixels buffer, values from mlx_get_data_addr()
typedef	struct s_image
{
	void	*img_ptr; // pointer to image struct
	char	*pixels_ptr; // points to the actual pixels
	int		*bpp;  // bits per pixel
	int		endian;
	int		line_len;
}			t_image;

//FRACTAL ID: image, hooks values
typedef	struct s_fractal
{
	char	*name;
	void 	*mlx_connection; //mlx_init
	void	*mlx_new_window; //mlx_new_window
	//image
	t_image	img;
	//add hooks members variable
}		t_fractal;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
static void	print_error(void);
void		ft_putstr(char *s);

#endif

