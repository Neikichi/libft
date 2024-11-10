/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:31:12 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 15:31:14 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Check if character is a digit (0-9)
/// 
/// This function checks whether the given
/// character `c` is a decimal digit
/// (between '0' and '9').
/// 
/// @param c The character to be checked
/// @return 1 if `c` is a digit, 0 otherwise
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
