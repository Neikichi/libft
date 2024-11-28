/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabd-sa <muabd-sa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:56:26 by muabd-sa          #+#    #+#             */
/*   Updated: 2024/09/12 20:45:22 by muabd-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_nbr(int nbr, char *base, int size)
{
	if (nbr >= size)
		print_nbr(nbr / size, base, size);
	ft_putchar(base[nbr % size]);
}

int	check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = 0;
	while (base[size] != '\0')
		size++;
	if (size <= 1)
		return ;
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		print_nbr(-(nbr / size), base, size);
		print_nbr(-(nbr % size), base, size);
		return ;
	}
	if (check_base(base) == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr == 0)
		ft_putchar('0');
	else
		print_nbr(nbr, base, size);
}
