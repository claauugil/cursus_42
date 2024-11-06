#include <unistd.h>

//recibe dos strings e imprime todos los caracteres que aparezcan en ambas,
// sin repetirlos y en el orden en el quue aparezcan en la primera

int main(int argc, char *argv[])
{
	int i;
	int j;
	unsigned char seen[256] = {0};

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					if(!seen[(unsigned char)argv[1][i]])
					{
						write(1, &argv[1][i], 1);
						seen[(unsigned char)argv[1][i]] = 1;
					}
					break;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}


