/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:20:47 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 16:21:13 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Write a string followed by a newline to a file descriptor
/// 
/// This function writes the string `s` to the file descriptor `fd`,
/// followed by a newline character.
/// 
/// @param s The string to be written
/// @param fd The file descriptor to write to (e.g., `1` for standard output)
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*int main(void)*/
/*{*/
/*    ft_putendl_fd("Hello, world!", 1);*/
/*    ft_putendl_fd("This is the first line.", 1);*/
/*    ft_putendl_fd("This is the second line.", 1);*/
/*    ft_putendl_fd("This is the third line.", 1);*/
/**/
/*    return 0;*/
/*}*/
