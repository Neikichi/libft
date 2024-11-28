/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:13:11 by azsaleh           #+#    #+#             */
/*   Updated: 2024/08/27 15:34:16 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			++j;
		}
		++i;
	}
}
/*
int	main(void)
{
	int	tab[] = {10, 8, 5, 42, 2};
	int	size = sizeof(tab) / sizeof(tab[0]);
	int	i;

	ft_sort_int_tab(&tab[0], size);
	i = 0;
	while (i < size)
	{
		if (i < size - 1)
			printf("%d, ", tab[i]);
		else
			printf("%d\n", tab[i]);
		++i;
	}
	return (0);
}
*/
