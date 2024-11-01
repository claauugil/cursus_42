#include <unistd.h>
#include <stdio.h>

char	*rev_print(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	while (str[len] >= 0)
	{
		write(1, &str[len], 1);
		len--;
	}
	write(1, "\n", 1);
	return(str);
}
int main(void)
{
  char *str = "Hello world";
  rev_print(str);
}
