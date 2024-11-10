/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:12:54 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 16:18:00 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/// @brief Move memory area
/// 
/// This function copies `n` bytes from the memory area `src`
/// to the memory area `dest`.
/// The memory areas may overlap, and the copying is done in
/// a way to handle such cases safely.
/// 
/// @param dest A pointer to the destination memory area
/// @param src A pointer to the source memory area
/// @param n The number of bytes to be copied
/// @return A pointer to the destination memory area (`dest`)
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	ptr_dest = dest;
	ptr_src = src;
	if (ptr_dest > ptr_src && ptr_dest < ptr_src + n)
	{
		ptr_dest += n - 1;
		ptr_src += n - 1;
		while (n--)
		{
			*ptr_dest-- = *ptr_src--;
		}
	}
	else
	{
		while (n--)
		{
			*ptr_dest++ = *ptr_src++;
		}
	}
	return (dest);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/**/
/*int main(void)*/
/*{*/
/*	char str1[] = "Standard memmove";*/
/*	ft_memmove(str1 + 5, str1, 7);*/
/*	printf("ft_memmove result: %s\n", str1);*/
/**/
/*	char str2[] = "Standard memmove";*/
/*	memmove(str2 + 5, str2, 7);*/
/*	printf("Standard memmove result: %s\n", str2);*/
/**/
/*	return 0;*/
/*}*/
