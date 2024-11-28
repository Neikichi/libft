/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabd-sa <muabd-sa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:29:02 by muabd-sa          #+#    #+#             */
/*   Updated: 2024/09/10 11:51:08 by muabd-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
/*
int main(void)
{
	char string[]= "Hello World";
	int length;

	printf("Length : %d", ft_strlen(&string[0]));
}
*/
