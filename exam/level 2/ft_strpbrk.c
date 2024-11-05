#include <stdio.h>
#include <string.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
    int len = 0;
    int j = 0;

    while (s1[len])
    {
        j = 0;
        while (s2[j] != '\0')
        {
            if (s1[len] == s2[j])
                return ((char *)&s1[len]);
            j++;
        }
        len++;
    }
    return (NULL);
}
int main (void)
{
    char *s1 = "holuiaaa";
    char *s2 = "jolu";
    printf("mia %s\n",ft_strpbrk(s1, s2));
    printf("real %s",strpbrk(s1, s2));
    return (0);
}
//busca la primera aparicion de cualquier caracter
// s2 en s1 //devuelve un puntero a la aparicion