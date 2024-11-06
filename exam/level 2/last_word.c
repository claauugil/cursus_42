#include <stdio.h>
#include <unistd.h>

size_t  ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}
int main (int argc, char *argv[])
{
    int end;
    int start;

    if (argc == 2)
    {
        end = ft_strlen(argv[1]) - 1;
        while (argv[1][end] == ' ' || argv[1][end] == '\t')
            end--;
        start = end;
        while (argv[1][start] != ' ' && argv[1][start] != '\t')//me incluye el _
            start--;
        start++;
        while (start <= end)
        {
            write(1, &argv[1][start], 1);
            start++;
        }
    }
    write(1, "\n", 1);
    return (0);
}