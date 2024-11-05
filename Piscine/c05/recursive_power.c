#include <stdio.h>


int ft_recursive_power(int nb, int power)
{
    if (power < 0)
        return (0);
    if (power == 0)
        return (nb);
    return (nb * ft_recursive_power(nb, power - 1));
}

int main(void)
{
    printf("%d\n", ft_recursive_power(1, 5));
    printf("%d\n", ft_recursive_power(2, 5));
    printf("%d\n", ft_recursive_power(3, 5));
    printf("%d\n", ft_recursive_power(4, 1));
    printf("%d\n", ft_recursive_power(-5, 5));
    return 0;
}