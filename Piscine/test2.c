#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *arr)
{
    int i;

    i = 0;
    while(arr[i] != '\0')
        i++;
    return (i);
}

char *rev_print(char *str)
{
    int len;
    int i;


    len = ft_strlen(str);
    i = len -1;

    while (i >= 0)
    {
        ft_putchar(str[i]);
        i--;
    }
    return (str);
}

int main(void)
{
    rev_print("hello");
    ft_putchar('\n');
    rev_print("");
    ft_putchar('\n');
    return (0);
}

