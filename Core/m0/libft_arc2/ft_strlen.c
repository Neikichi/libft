/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:58:19 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 16:58:39 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/// @brief Calculate the length of a string
/// 
/// This function counts the number of characters in the string `str`
/// until the null terminator is encountered.
/// 
/// @param str The input string whose length is to be calculated
/// @return The length of the input string (excluding the null terminator)
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}
