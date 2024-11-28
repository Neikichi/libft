/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:29:48 by vlow              #+#    #+#             */
/*   Updated: 2024/09/11 13:43:13 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*st;

	st = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (st);
}

char	*ft_strdup(char *src)
{
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					idx;
	struct s_stock_str	*ptr;

	idx = 0;
	ptr = malloc(sizeof(*ptr) * (ac + 1));
	if (!ptr)
		return (NULL);
	while (idx < ac)
	{
		(ptr + idx)->size = ft_strlen(av[idx]);
		(ptr + idx)->str = av[idx];
		(ptr + idx)->copy = ft_strdup(av[idx]);
		idx++;
	}
	ptr[idx].str = NULL;
	return (ptr);
}
