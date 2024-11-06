#include <stdio.h>

int max(int *tab, unsigned int len)
{
    int i = 0;
    int result = 0;

    if (len == 0)
        return (0);
    result = tab[i];
    while (i < len)
    {
        if (result < tab[i])
            result = tab[i];
        i++;
    }
    return result;
}
int main(void)
{
    int array[] = {3, 7, 1, 15, 9, 12};
    unsigned int len = sizeof(array) / sizeof(array[0]);
    int result;

    result = max(array, len);

    if (len == 0)
        printf("Array length is zero, max: 0\n");
    else
        printf("The maximum value is: %d\n", result);

    return 0;
}

//devuelve el numero mas grande 
//encontrado en un array de ints (tabs)
