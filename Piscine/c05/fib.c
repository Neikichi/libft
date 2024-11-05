#include <stdio.h>


int ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    if (index == 0)
        return (0);
    if (index == 1 || index == 2)
        return (1);
    return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int main(void)
{
    printf("%d\n", ft_fibonacci(-100));
    printf("%d\n", ft_fibonacci(3));
    printf("%d\n", ft_fibonacci(4));
    printf("%d\n", ft_fibonacci(5));
    printf("%d\n", ft_fibonacci(8));
    return 0;
}