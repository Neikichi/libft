/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:56:25 by vlow              #+#    #+#             */
/*   Updated: 2024/09/08 01:03:24 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	idx;
	int	cnt;

	idx = 0;
	if (*to_find == '\0')
		return (str);
	while (str[idx] != '\0')
	{
		cnt = 0;
		while (to_find[cnt] == str[idx + cnt])
		{
			if (to_find[cnt + 1] == '\0')
			{
				return (str + idx);
			}
			cnt++;
		}
		idx++;
	}
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	int	idx;
	int	dest_len;
	int	src_len;

	idx = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	while (src[idx] != '\0')
	{
		dest[dest_len + idx] = src[idx];
		idx++;
	}
	dest[dest_len + idx] = '\0';
	return (dest);
}

void	ft_catsep(int size, char **strs, char *sep, char *result)
{
	int	idx;

	idx = 0;
	result[0] = '\0';
	while (idx < size)
	{
		ft_strcat(result, strs[idx]);
		if (idx < size - 1)
			ft_strcat(result, sep);
		idx++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		idx;
	int		len;
	int		sep_size;
	char	*result;

	idx = 0;
	len = 0;
	sep_size = ft_strlen(sep) * (size - 1);
	if (size == 0)
	{
		result = malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	while (idx < size)
	{
		len += ft_strlen(strs[idx]);
		idx++;
	}
	result = malloc(sizeof(char) * (len + sep_size) + 1);
	if (!result)
		return (NULL);
	ft_catsep(size, strs, sep, result);
	return (result);
}
