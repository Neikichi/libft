/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:50:49 by vlow              #+#    #+#             */
/*   Updated: 2024/09/07 13:53:21 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	cnt;

	cnt = 0;
	if (src == NULL)
		return (0);
	while (*src)
	{
		src++;
		cnt++;
	}
	return (cnt);
}

char	*ft_strcpy(char *dest, char *src)
{
	if (src == NULL || dest == NULL)
		return (NULL);
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		size;
	char	*dup;

	if (src == NULL)
		return (NULL);
	size = ft_strlen(src);
	dup = malloc(size * 1 + 1);
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}
