#include <unistd.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putnbr(int nb)
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
    int a, b, c;
    while (a != 98)
    {
        if(b == 99 && a < 98 && c == 0)
        {
            c++;
            b = 1;
            a++;  
        }
        else if (a == 98 && b == 99)
        {
            break;
        }
        else if (c != 0)
        {
            a++;
        }
        b++;
        ft_print(a, b);
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