#include <stdio.h>

size_t ft_strcsnp(const char  *s, const char *reject)
{
	int len = 0;
	int j = 0;

	while (s[len] != '\0')
	{
		while (reject[j] != '\0')
		{
			j = 0;
			if (s[len] == reject[j])
				return (len);
			j++;
		}
		len++;
	}
	return (len);
}
//la funcion devuelve a longitud de la cadena s mientras no contenga caracteres de reject
