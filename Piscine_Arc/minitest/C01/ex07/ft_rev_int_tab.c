/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:33:35 by azsaleh           #+#    #+#             */
/*   Updated: 2024/08/27 15:32:52 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	v_top;
	int	v_end;

	i = 0;
	while (i < size / 2)
	{
		v_top = tab[i];
		v_end = tab[(size - 1) - i];
		tab[i] = v_end;
		tab[(size - i) - 1] = v_top;
		++i;
	}
}
/*
int	main(void)
{
	int	tab[] = {1, 2, 3, 60, 4, 21, 42};
	int	size = sizeof(tab) / sizeof(tab[0]);
	int	i;

	ft_rev_int_tab(&tab[0], size);
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
