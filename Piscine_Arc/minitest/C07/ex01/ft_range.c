/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:44:53 by vlow              #+#    #+#             */
/*   Updated: 2024/09/10 12:36:32 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	dif;
	int	idx;

	if (min >= max)
		return (NULL);
	dif = max - min;
	range = malloc(dif * sizeof(int));
	if (!range)
		return (NULL);
	idx = 0;
	range[0] = min;
	while (++idx < dif)
		range[idx] = ++min;
	return (range);
}
