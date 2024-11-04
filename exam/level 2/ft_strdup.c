#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t ft_strlen(char *src)
{
	size_t len = 0;
	while (src[len] != '\0')
		len++;
	return (len);
}
char *ft_strdup(char  *src)
{
	int i = 0;
	char *dup;

	dup = (char *)malloc(ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*int main ()
{
	char *src = "Chaoooooooooooooooooooooooo";
	printf("mia: %s\n", ft_strdup(src));
	printf("mia: %s\n", strdup(src));
	return (0);
}*/
//duplica una cadena en una variable nueva
