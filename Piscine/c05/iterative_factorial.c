#include <stdio.h>


int ft_iterative_factorial(int nb)
{
    int idx;
    int amt;

    idx = 0;
    amt = 1;
    if (nb < 0)
        return (0);
    while (++idx <= nb)
        amt *= idx;
    return (amt);
}

int main(void)
{
    printf("%d\n", ft_iterative_factorial(1));
    printf("%d\n", ft_iterative_factorial(2));
    printf("%d\n", ft_iterative_factorial(3));
    printf("%d\n", ft_iterative_factorial(4));
    printf("%d\n", ft_iterative_factorial(-5));
    return 0;
}