/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:05:19 by azsaleh           #+#    #+#             */
/*   Updated: 2024/09/12 20:03:28 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		++i;
	}
}
/*
int	main(void)
{
	char	c[] = "hello world\n";

	ft_putstr(&c[0]);
	return (0);
}
*/
