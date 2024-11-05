#include <stdio.h>


int ft_iterative_power(int nb, int power)
{
    int idx;
    int amt;

    idx = 0;
    amt = nb;
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    while (++idx < power)
        amt *= nb;
    return (amt);
}

int main(void)
{
    printf("%d\n", ft_iterative_power(1, 0));
    printf("%d\n", ft_iterative_power(2, 5));
    printf("%d\n", ft_iterative_power(3, 5));
    printf("%d\n", ft_iterative_power(4, 1));
    printf("%d\n", ft_iterative_power(-5, 5));
    return 0;
}