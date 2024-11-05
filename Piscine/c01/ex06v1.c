#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putchar((nb / 10) + '0');
		ft_putchar((nb % 10) + '0');
	}
	else
	{
		ft_putchar('0');
		ft_putchar(nb + '0');
	}
}

void	ft_print(int a, int b)
{
	if (a == 98 && b == 99)
	{
		ft_putnbr(a);
		ft_putchar(' ');
		ft_putnbr(b);
	}
	else
	{
		ft_putnbr(a);
		ft_putchar(' ');
		ft_putnbr(b);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	c = 0;
	while (c == 0)
	{
        c = 1;
        while (a != 98)
        {
            b++;
            if (b == 99 && a != 98)
            {
                ft_print(a, b);
                a++;
                b = a + 1;
                c = 0;
            }
            ft_print(a, b);
        }
        
	}
}

int main()
{
	ft_print_comb2();
}