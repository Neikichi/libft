/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:56:46 by vlow              #+#    #+#             */
/*   Updated: 2024/08/29 21:59:18 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	ct;

	ct = 0;
	while (*str)
	{
		str++;
		ct++;
	}
	return (ct);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while ((idx < ft_strlen(s1)) || (idx < ft_strlen(s2)))
	{
		cnt = cnt + (s1[idx] - s2[idx]);
		if (cnt != 0)
		{
			return (cnt);
		}
		idx++;
	}
	return (0);
}
