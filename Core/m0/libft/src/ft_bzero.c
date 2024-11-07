#include "libft.h"

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

#include <stdio.h>  // Library used only in main for test cases
#include <string.h> // Required for memset used in the main

int main(void)
{
  char buffer[10] = "123456789";

  // Edge test case: n = 0, no bytes should be modified
  ft_bzero(buffer, 0);
  printf("ft_bzero with n=0: \"%s\"\n", buffer);  // Expected: "123456789"

  // Compare with memset with zero length
  memset(buffer, 'X', 5);
  buffer[5] = '\0';
  ft_bzero(buffer, 0);
  printf("Comparison after memset and ft_bzero: \"%s\"\n", buffer); // Expected: "XXXXX"

  return 0;
}
