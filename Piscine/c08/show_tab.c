#include <unistd.h>
#include "ft_stock_str.h"

// typedef struct s_stock_str
// {
//     int size;
//     char *str;
//     char *copy;
// }   t_stock_str;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int idx;

	idx = 0;
	while (par[idx].str)
	{
		ft_putstr(par[idx].str);
		ft_putnbr(par[idx].size);
		ft_putchar('\n');
		ft_putstr(par[idx].copy);
		idx++;
	}
}