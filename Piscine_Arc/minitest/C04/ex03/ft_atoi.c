/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabd-sa <muabd-sa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:11:44 by muabd-sa          #+#    #+#             */
/*   Updated: 2024/09/12 20:40:47 by muabd-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	space_sym(int *i, int *sign, char *str)
{
	int	count;

	count = 0;
	while (str[*i] <= 32)
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			count++;
		(*i)++;
	}
	if (count % 2 == 1)
		*sign = -1;
	else
		*sign = 1;
}

int	ft_atoi(char *str)
{
	char const	*num = "0123456789";
	int			i;
	int			j;
	int			sign;
	int			result;

	result = 0;
	i = 0;
	j = 0;
	space_sym(&i, &sign, str);
	while (str[i] >= 48 && str[i] <= 57)
	{
		j = 0;
		while (j < 10)
		{
			if (str[i] == num[j])
			{
				result = result * 10 + (str[i] - '0');
				break ;
			}
			j++;
		}
		i++;
	}
	return (result * sign);
}
