#include <unistd.h>

int main (int argc, char *argv[])
{
	int i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = (argv[1][i] - 'a' + 13) % 26 + 'a';
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = (argv[1][i] - 'A'+ 13) % 26 + 'A';
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, &argv[1][i], 1);
	return (0);
}

/*
argv[1][i] - 'a' convierte el caracter actual en su posicion del alfabeto
+ 13 para rotarlo 13 mas adelante
%26 por si al sumar se pasa de 'z' vuelve al inicio del alfabeto
*/
