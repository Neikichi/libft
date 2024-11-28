/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:24:56 by azsaleh           #+#    #+#             */
/*   Updated: 2024/08/27 15:23:15 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main(void)
{
	int	i;
	int	j;

	i = 42;
	j = 13;
	ft_swap(&i, &j);
	printf("i:%d j:%d\n", i, j);
	return (0);
}
*/
