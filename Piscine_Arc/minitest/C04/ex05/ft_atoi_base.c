/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabd-sa <muabd-sa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:51:15 by muabd-sa          #+#    #+#             */
/*   Updated: 2024/09/12 21:04:20 by muabd-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_base(char *base)
{
	int	length;
	int	i;
	int	j;

	length = 0;
	while (base[length] != '\0')
		length++;
	if (length <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
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
	return (length);
}

//checking string isspace and return sign value
int	valid_str(char *str, int *i)
{
	int	neg;

	neg = 0;
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v'
		|| str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ' )
		(*i)++;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			neg++;
		(*i)++;
	}
	if (neg % 2 == 1)
		return (-1);
	else
		return (1);
}

int	convert_num(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	b_length;
	int	sign;
	int	result;
	int	temp;
	int	i;

	b_length = check_base(base);
	if (b_length == 0)
		return (0);
	i = 0;
	sign = valid_str(str, &i);
	result = 0;
	while (str[i] != '\0')
	{
		temp = convert_num(base, str[i]);
		if (temp == -1)
			return (0);
		else
			result = result * b_length + temp;
		i++;
	}
	return (result * sign);
}
