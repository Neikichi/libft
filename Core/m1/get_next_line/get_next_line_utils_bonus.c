/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:56:46 by vlow              #+#    #+#             */
/*   Updated: 2024/11/18 11:59:54 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	src_len;
// 	size_t	dest_len;
//
// 	if ((!dst || !src) && size == 0)
// 		return (0);
// 	i = 0;
// 	src_len = ft_strlen(src);
// 	dest_len = ft_strlen(dst);
// 	if (dest_len >= size)
// 		return (src_len + size);
// 	while (src[i] != '\0' && (dest_len + i) < (size - 1))
// 	{
// 		dst[dest_len + i] = src[i];
// 		i++;
// 	}
// 	dst[dest_len + i] = '\0';
// 	return (dest_len + src_len);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		i;
	int		dest_len;

	if (!s1 || !s2)
		return (NULL);
	buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buffer)
		return (NULL);
	dest_len = ft_strlen(s1);
	i = 0;
	ft_strlcpy(buffer, s1, ft_strlen(s1) + 1);
	while (s2[i])
	{
		buffer[dest_len + i] = s2[i];
		i++;
	}
	buffer[dest_len + i] = '\0';
	return (buffer);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if ((char)c == '\0')
// 		return ((char *)s);
// 	return (NULL);
// }
