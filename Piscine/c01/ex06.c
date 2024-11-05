#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb, int arr[], int cond)
{
	int	idx;

	idx = 0;
	if (cond == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	while (idx < nb)
	{
		ft_putchar(arr[idx] + '0');
		idx++;
	}
}

void	ft_swap(int nb, int arr[])
{
	int	idx;

	idx = nb - 2;
	while (idx >= 0 && arr[idx] == 9 - (nb - 1 - idx))
	{
		idx--;
	}
	arr[idx]++;
	arr[idx + 1] = arr[idx] + 1;
}
	
void	ft_print_combn(int nb)
{
	int	arr[10];
	int	idx;
	int	nnb;

	nnb = 10 - nb;
	idx = 0;
	while (idx < nb)
	{
		arr[idx] = idx;
		idx++;
	}
	ft_putnbr(nb, arr, 0);
	while (arr[0] != nnb || arr[nb - 1] != 9)
	{
		if (arr[nb - 1] != 9)
		{
			arr[nb - 1]++;
		}
		else
		{
			ft_swap(nb, arr);
		}
		ft_putnbr(nb, arr, 1);
	}
}
