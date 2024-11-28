/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:17:07 by vlow              #+#    #+#             */
/*   Updated: 2024/08/30 23:19:01 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	idx;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	idx = 0;
	while (src[idx] != '\0' && dest_len + idx < size - 1)
	{
		dest[dest_len + idx] = src[idx];
		idx++;
	}
	dest[dest_len + idx] = '\0';
	return (dest_len + src_len);
}
