//verifica si el numero es potencia de dos, devuelve 0 si no y 1 si si
#include <stdio.h>

int 	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
	{
		n = n / 2;
	}
	if (n == 1)
		return (1);
	else
		return (0);
}
int main()
{
	int i = 8;
	printf("%d",is_power_of_2(i));
	return (0);
}
