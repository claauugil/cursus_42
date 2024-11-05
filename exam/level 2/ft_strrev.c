#include <stddef.h>
#include <stdio.h>

size_t ft_strlen (char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
char *ft_strrev(char *str)
{
    int i = 0;
    int j = ft_strlen(str) - 1;
    char temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j]; 
        str[j] = temp;
        i++;
        j--;
    }
    return(str);
}
/*int main (void)
{
    char string[] = "jelou";
    printf("%s", ft_strrev(string));
    return(0);
}*/