#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb, int arr[], int s_pr)
{
    int index;

    if (s_pr == 1)
    {
        ft_putchar(',');
        ft_putchar(' ');
    }
    index = 0;
    while (index < nb)
    {
        ft_putchar(arr[index] + '0');
        index++;
    }
}

int power(int n)
{
    int ten = 10;
    int count = 1;

    while (count < n)
    {
        ten = ten * 10;
        count++;
    }
    return ten;
}

void    print8(int nb)
{
    int arr[nb];
    int n_nb = 10 - nb;
    int index = 0;

    while (index < nb)
    {
        arr[index] = index;
        index++;
    }
    ft_putnbr(nb, arr, 0);
    while (arr[0] != n_nb || arr[nb - 1] != 9)
    {
        if (arr[nb - 1] != 9)
        {
            arr[nb - 1]++;
        }
        else
        {
            int idx;
            idx = nb - 2;
            while (idx >= 0 && arr[idx] == 9 - (nb - 1 - idx))
            {
                idx--;
            }
            arr[idx]++;
            arr[idx + 1] = arr[idx] + 1;
            // new arr nb
            printf(" array idx = %d\n", idx);
            
        }
        ft_putnbr(nb, arr, 1);
    }  
}

void    ft_print_combn(int n)
{
    int arr[n];

}

int main(void)
{
    print8(2);
    // printf("power val - %d \n'", power(3));

    return 0;

}