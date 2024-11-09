#include "libft.h"
#include <stdio.h>

/// @brief Set memory area to zero
/// 
/// This function writes zeroes to a byte string. If `n` is zero, `ft_bzero()`
/// does nothing.
/// 
/// @param s Pointer to the memory area to be zeroed
/// @param n Number of bytes to set to zero
/// @return This function does not return a value
void ft_bzero(void *s, size_t n)
{
  ft_memset(s, '\0', n);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/*int main(void)*/
/*{*/
/*  char buffer[] = "123456789";*/
/**/
/*  ft_bzero(buffer, 0);*/
/*  printf("ft_bzero with n=0: \"%s\"\n", buffer);*/
/**/
/*  memset(buffer, 'X', 5);*/
/*  buffer[5] = '\0';*/
/*  ft_bzero(buffer, 0);*/
/*  printf("Comparison after memset and ft_bzero: \"%s\"\n", buffer);*/
/**/
/*  return 0;*/
/*}*/
