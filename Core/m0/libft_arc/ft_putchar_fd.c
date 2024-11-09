/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:20:20 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 16:20:37 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/// @brief Write a character to a file descriptor
/// 
/// This function writes the character `c` to the file descriptor `fd`.
/// 
/// @param c The character to be written
/// @param fd The file descriptor to write to (e.g., `1` for standard output)
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
