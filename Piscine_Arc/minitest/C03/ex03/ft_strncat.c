/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:37:05 by vlow              #+#    #+#             */
/*   Updated: 2024/09/02 16:59:59 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*temp;
	unsigned int	idx;

	temp = dest;
	idx = 0;
	while (*temp != '\0')
	{
		temp++;
	}
	while (*src != '\0' && idx < nb)
	{
		*temp++ = *src++;
		idx++;
	}
	*temp = '\0';
	return (dest);
}
