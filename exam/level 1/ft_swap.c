#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/*int main (void)
{
	int p = 5;
	int c = 6;
	printf("numeros normales %d y %d\n", p, c);
	ft_swap(&p ,&c);
	printf("numeros cambiados %d y %d", p, c);
	return (0);
}*/
