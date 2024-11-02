#include <unistd.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putnbr(int nb)
{
    if (nb > 9)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    else
    {
        ft_putchar(nb + '0');
    }
}

void    ft_print(int a, int b)
{
    if (a == 98 && b == 99)
    {
        ft_putnbr(a);
        ft_putchar(' ');
        ft_putnbr(b);
        ft_putchar('$');
        ft_putchar('>');
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

void    mtest(void)
{
    int a[3];

	a[0] = 0;
	while (a[0] <= 7)
	{
		a[1] = a[0] + 1;
		while (a[1] <= 8)
		{
			a[2] = a[1] + 1;
			while (a[2] <= 9)
			{
				ft_putnbr(a[0]);
				ft_putnbr(a[1]);
				ft_putnbr(a[2]);
				if (a[0] != 7 || a[1] != 8 || a[2] != 9)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				a[2]++;
			}
			a[1]++;
		}
		a[0]++;
	}
}

int main()
{
    mtest();


    // ft_putnbr(2147483647);
    // ft_putnbr(-2147483648);
    // ft_putnbr(21474);
    // ft_putnbr(-83647);

    return 0;
}