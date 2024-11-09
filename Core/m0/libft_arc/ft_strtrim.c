/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:03:10 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 17:04:21 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/// @brief Trim characters from the beginning and end of a string
/// 
/// This function removes all characters in `set` from both the beginning and
/// the end of the string `s1`. The trimmed string is returned
/// as a new dynamically allocated string.
/// 
/// @param s1 The input string to be trimmed
/// @param set The set of characters to be removed from `s1`
/// @return A pointer to the newly trimmed string, 
///			or `NULL` if allocation fails
char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	char		*buffer;
	const char	*end;

	start = s1;
	while (*start && ft_strchr(set, *start))
	{
		start++;
	}
	end = s1 + ft_strlen(s1) - 1;
	while (ft_strchr(set, *end) && end >= start)
	{
		end--;
	}
	buffer = malloc(sizeof(char) * (end - start + 2));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, start, (end - start + 2));
	return (buffer);
}

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*		const char *s1 = "+,++Hello, world!++,+";*/
/*		const char *set = "+,";*/
/*		char *result = ft_strtrim(s1, set);*/
/*		if (result)*/
/*		{*/
/*				printf("ft_strtrim result: '%s'\n", result);*/
/*				free(result);*/
/*		}*/
/**/
/*		return 0;*/
/*}*/
