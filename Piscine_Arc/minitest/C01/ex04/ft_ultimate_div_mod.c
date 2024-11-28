/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:54:26 by azsaleh           #+#    #+#             */
/*   Updated: 2024/08/27 15:27:35 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = temp / *b;
	*b = temp % *b;
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 30;
	b = 4;
	ft_ultimate_div_mod(&a, &b);
	printf("div:%d mod:%d\n", a, b);
	return (0);
}
*/
