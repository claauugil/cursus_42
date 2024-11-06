#include <unistd.h>

int main(int argc, char *argv[])
{
	int i =  0;
	int j = 0;

	if (argc == 3)
	{
		while (argv[2][j])
		{
			if(argv[2][j] == argv[1][i])
				i++;
			j++;
		}
		if (argv[1][i] == '\0') //verifica si llego al final de la cadena y encontro las letras en orden
		{
			i = 0; // para imprimir desde el principio
			while(argv[1][i])
			{
				write(1, &argv[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
