#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void putnbr(int num)
{
	if (num >= 10)
	{
		putnbr(num / 10);
		putnbr(num % 10);
	}
	else
		ft_putchar(num + 48);
}
/*void write_num(int num)
{
	char	*str = "0123456789";

	if (num > 9)
		write_num(num / 10);
	write(1, &str[num % 10], 1);
}*/

int main (void)
{
	int num = 1;

	while (num <= 100)
	{
		if (num % 3 == 0 && num %5 == 0)
			write(1, "fizzbuzz", 8);
		else if (num %3 == 0)
			write (1, "fizz", 4);
		else if (num %5 == 0)
			write(1, "buzz", 4);
		else
			putnbr(num);
		num++;
		write(1, "\n", 1);
	}
	return (0);
}
