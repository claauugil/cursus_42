/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 14:15:04 by cgil              #+#    #+#             */
/*   Updated: 2025-01-13 14:15:04 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fract_ol.h"

#include <stdio.h>

typedef	struct s_complex_n
{
	double	real;
	double	ima;
}				t_complex_n;

int	main() // check if number is in the plane
{
	//these make the point
	t_complex_n	z;
	t_complex_n	c;
	int i;
	double	temp_real;

	z.real = 0;
	z.ima = 0;
	c.real = 0.25,
	c.ima = 0.4;
	i = 0;
	temp_real = 0;

	while (i < 42)
	{ // formula general: z =  z² + c // zn + 1 = sz² +c
		//to square z
		temp_real = (z.real * z.real - (z.ima * z.ima)); //x² - y² square both and subtract
		z.ima = 2 * z.real * z.ima; // multiply 2 * x & y
		z.real = temp_real;

		// add c
		z.real += c.real;
		z.ima += c.ima;
		printf("iteration n -> %d real %f ima %f\n", i, z.real, z.ima);
		i++;
	}
}
