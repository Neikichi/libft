#include <stdio.h>
#include <unistd.h>
int sol = 0;
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_putnbr(int nb)
{
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
	return (nb);
}

void print_result(int *grid)
{
	int idx;

	idx = 0;
	while (idx < 10)
	{
		ft_putnbr(grid[idx]);
		idx++;
	}
    ft_putchar('\n');
    sol++;
}

int is_valid(int *grid, int col)
{
    int idx;

    idx = 0;

    while (idx < col)
    {
        if (grid[idx] == grid[col])
            return (0);
        if (grid[idx] - idx == grid[col] - col || grid[idx] + idx == grid[col] + col)
        {
            return (0);
        }
        // if (grid[idx] == grid[col] + (col - idx) || grid[col] == grid[idx] - (col - idx))
        // {
        //     return (0);
        // }
        idx++;
    }
    return (1);
    
}

void ft_check(int *grid, int col)
{
    int idx;

    if (col == 10)
    {
        print_result(grid);
        return ;
    }
    idx = 0;
    while (idx < 10)
    {
        grid[col] = idx;
        if (is_valid(grid, col))
        {
            ft_check(grid, col + 1);
        }
        idx++;
    }   
}

void    ft_ten_queen(void)
{
    int grid[10];
    int idx;

    idx = 0;
    while (idx < 10)
    {
        grid[idx] = -1;
        idx++;
    }
    ft_check(grid, 0);
}

int main(void)
{
    ft_ten_queen();
    ft_putnbr(sol);
    ft_putchar('\n');
    return (0);
}