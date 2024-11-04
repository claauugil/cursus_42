#include <unistd.h>
#include <stdio.h>

char *rev_print(char *str)
{
	int i =  0;
	while(str[i] != '\0')
		i++;
	while (i > 0)
	{
		i--;
		write(1, &str[i], 1);
	}
	write(1, "\n", 1);
	return (str);
}
/*char	*rev_print(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	while (len > 0)
	{
		len--;
		write(1, &str[len], 1);
	}
	write(1, "\n", 1);
	return(str);
}*/
int main(void)
{
  char *str = "Hello world";
  rev_print(str);
  return(0);
}
