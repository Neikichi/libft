/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:15:18 by vlow              #+#    #+#             */
/*   Updated: 2024/09/09 01:11:54 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strlcpy(char *dest, char *src, int len)
{
	int	idx;

	idx = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (idx < len)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

int	ft_chkset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	get_word(char *str, char *charset)
{
	int	cnt;
	int	flag;
	int	set;

	cnt = 0;
	flag = 0;
	while (*str)
	{
		set = 0;
		if (ft_chkset(*str, charset))
			set = 1;
		if (set == 0 && flag == 0)
		{
			cnt++;
			flag = 1;
		}
		if (set == 1)
			flag = 0;
		str++;
	}
	return (cnt);
}

char	**ft_split_ex(char *str, char *charset, char **result)
{
	int		idx;
	int		len;
	char	*find;

	idx = 0;
	while (*str)
	{
		while (*str && ft_chkset(*str, charset))
			str++;
		if (*str)
		{
			find = str;
			while (*find && !ft_chkset(*find, charset))
				find++;
			len = find - str;
			result[idx] = malloc(sizeof(char) * (len + 1));
			if (!result)
				return (NULL);
			ft_strlcpy(result[idx], str, len);
			idx++;
			str = find;
		}
	}
	result[idx] = NULL;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		size;

	if (*str == '\0')
	{
		result = malloc(sizeof(char *) * 1 + 1);
		if (!result)
			return (NULL);
		result[0] = NULL;
		return (result);
	}
	size = get_word(str, charset);
	result = malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	return (ft_split_ex(str, charset, result));
}
