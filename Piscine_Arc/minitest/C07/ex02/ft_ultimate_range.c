/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:53:51 by vlow              #+#    #+#             */
/*   Updated: 2024/09/07 13:56:02 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	dif;
	int	idx;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	dif = max - min;
	*range = malloc(dif * sizeof(int));
	if (!*range)
	{
		*range = NULL;
		return (-1);
	}
	idx = 0;
	(*range)[0] = min;
	while (++idx < dif)
		(*range)[idx] = ++min;
	return (dif);
}
