/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:04:29 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 17:05:14 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/// @brief Create a substring from a given string
/// 
/// Allocate (with malloc(3)) and return a new string from the string s.
/// This new string starts at index 'start' and has a maximum size of 'len'.
/// 
/// @param s The original string from which the substring will be created
/// @param start The starting index of the substring in `s`
/// @param len The maximum length of the substring
/// @return A pointer to the newly created substring, 
///			or `NULL` if allocation fails
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	buffer = malloc(sizeof(char) * len + 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s + start, len + 1);
	return (buffer);
}

/*int main(void)*/
/*{*/
/*	const char *str1 = "Hello, world!";*/
/*	char *result1 = ft_substr(str1, 7, 5);*/
/*	if (result1)*/
/*	{*/
/*		printf("ft_substr result: '%s'\n", result1);*/
/*		free(result1);*/
/*	}*/
/**/
/*	return 0;*/
/*}*/
