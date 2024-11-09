/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:21:58 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 16:22:11 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Write a string to a file descriptor
/// 
/// This function writes the string `s` to the file descriptor `fd`.
/// 
/// @param s The string to be written
/// @param fd The file descriptor to write to (e.g., `1` for standard output)
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

/*int main(void)*/
/*{*/
/*		ft_putstr_fd("Hello, world!", 1);*/
/*		ft_putchar_fd('\n', 1);*/
/**/
/*		return 0;*/
/*}*/
