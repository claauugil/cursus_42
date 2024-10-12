/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 14:17:07 by cgil              #+#    #+#             */
/*   Updated: 2024-10-12 14:17:07 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long long num, int cap)
{
	int	len;
	char	low;
	char	up;

	len = 0;
	low = "0123456789abcdef"[num % 16];
	up = "0123456789ABCDEF"[num % 16];
	if (num >= 16)
		len += ft_puthexa(num / 16, cap);
	if (!cap) // si cap es cero (t)
		len +=ft_putchar(low);
	else //cap (f)
		len += ft_putchar(up);
	return (len);
}
