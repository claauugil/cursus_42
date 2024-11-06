#include <stddef.h>
#include <stdio.h>
#include <string.h>
//desde el inicio

 //devuelve la longitud de la cadena s mientras solo
 // contenga los caracteres de accept
char	*ft_strchr(const char *s1, int c)
{
	unsigned char ch = (unsigned char) c;
	while (*s1 != '\0')
	{
		if (*s1 == ch)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
size_t ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == NULL)
			return (i);
		i++;
	}
	return i;
}

int main() {
    char *str= "comoestaslalalala";
    char *accept= "como";

    size_t len = ft_strspn(str, accept);
	size_t leni = strspn(str, accept);

    printf("La longitud del segmento inicial es: %zu\n", len);
	printf("La longitud del segmento inicial es: %zu\n", leni);
    return 0;
}

/*int main ()
{
	char *s1 = "Hola";
	char *s2 = "Hola";
	printf("%zu\n", ft_strspn(s1, s2));
	printf("%zu\n", strspn(s1, s2));
}*/
