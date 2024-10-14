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

static int	format_manager(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_putchar('%');
	else if (format == 'x')
		len += ft_puthexa(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		len += ft_puthexa(va_arg(args, unsigned int), 1);
	else if (format == 'p')
		len += ft_putptr(va_arg(args, void *));
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else
		{
			i++;
			if (str[i] != '\0')
				len += format_manager(str[i], args);
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*int main() {
    char *str;
    int number = 42;
    unsigned int unsigned_number = 12345;
	int *ptr = &number;
	int *ptr2 = NULL;

    // Uso de ft_printf
    ft_printf("Prueba de ft_printf:\n");
    ft_printf("Cadena: %s\n", str);
    ft_printf("Número: %d\n", number);
    ft_printf("Número sin signo: %u\n", unsigned_number);
    ft_printf("Caracter: %c\n", 'A');
    ft_printf("Porcentaje: %%\n");
	ft_printf("Hexadecimal minuscula %x\n", 59);
	ft_printf("Hexadecimal mayuscula %X\n", 78);
	ft_printf("%X\n", -78);
	ft_printf("%p\n", ptr );
	ft_printf("Puntero %p\n",ptr2 );

    // Uso de printf para comparación
    printf("\nPrueba de printf:\n");
    printf("Cadena: %s\n", str);
    printf("Número: %d\n", number);
    printf("Número sin signo: %u\n", unsigned_number);
    printf("Caracter: %c\n", 'A');
    printf("Porcentaje: %%\n");
	printf("Hexadecimal minuscula %x\n", 59);
	printf("Hexadecimal mayuscula %X\n", 78 );
	printf("%X\n", -78);
	printf("Puntero %p\n",ptr2 );

    return 0;
}*/
