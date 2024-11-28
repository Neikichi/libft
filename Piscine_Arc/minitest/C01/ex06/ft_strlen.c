/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:14:27 by azsaleh           #+#    #+#             */
/*   Updated: 2024/08/27 15:30:30 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}
/*
int	main(void)
{
	int		i;
	char	c[] = "hello world\n";

	i = ft_strlen(&c[0]);
	printf("length:%d\n", i);
	return (0);
}
*/
