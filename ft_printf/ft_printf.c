/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-10 16:33:58 by cgil              #+#    #+#             */
/*   Updated: 2024-10-10 16:33:58 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//procesa un unico caracter (tipo de formato actual)
static int	format_manager(const char format, va_list args)
{
	int	len; //caracteres impresos

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if(format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));

	return (len);
}
int	ft_printf(char const *str, ...)
{
	va_list	args;
	int	i;
	int	len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%') //si solo es una string
			len += ft_putchar(str[i]);
		else // si es %
		{
			i++; // para ver el siguiente caracter  (ef)
			if (str[i] != '\0')
				len += format_manager(str[i], args); //si son especificadores
			/*else
				len += ft_putchar('%');*/ // si es el caracter %
		}
		i++;
	}
	va_end(args);
	return (len);
}
int main (void)
{
	ft_printf("el numero es %d", 10);
	return 0;
}
