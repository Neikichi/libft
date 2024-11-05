#include <stdio.h>


int ft_sqrt(int nb)
{
    int g;
    int lg;

    g = nb / 2;
    lg = 0;
    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (nb);
    while (lg != g)
    {
        lg = g;
        g = (g + nb / g) / 2;
    }
    if (g * g == nb)
        return (g);
    else
        return (0);
}

int main(void)
{
    printf("%d\n", ft_sqrt(-100));
    printf("%d\n", ft_sqrt(2));
    printf("%d\n", ft_sqrt(4));
    // printf("%d\n", ft_sqrt(5));
    // printf("%d\n", ft_sqrt(8));
    return 0;
}