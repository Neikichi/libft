/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:05:32 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 17:06:37 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c);

/// @brief Convert an uppercase character to lowercase
/// 
/// This function converts an uppercase character to its corresponding
/// lowercase character.
/// If the character is not an uppercase letter, it is returned unchanged.
/// 
/// @param c The character to be converted
/// @return The converted lowercase character, or the original character
///			if it is not uppercase
int	ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		return (c + 32);
	}
	return (c);
}

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
