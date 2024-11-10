/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:32:52 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 15:33:24 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Check if character is printable
/// 
/// This function checks whether the given 
/// character `c` is a printable
/// character, including space, but excluding 
/// control characters.
/// 
/// @param c The character to be checked
/// @return 1 if `c` is a printable character, 0 otherwise
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
