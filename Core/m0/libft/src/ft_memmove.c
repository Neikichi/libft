#include "libft.h"


/// @brief Move memory area
/// 
/// This function copies `n` bytes from the memory area `src` to the memory area `dest`.
/// The memory areas may overlap, and the copying is done in a way to handle such cases safely.
/// 
/// @param dest A pointer to the destination memory area
/// @param src A pointer to the source memory area
/// @param n The number of bytes to be copied
/// @return A pointer to the destination memory area (`dest`)
void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *ptr_dest;
    const unsigned char *ptr_src;
    size_t i;

    i = 0;
    ptr_dest = dest;
    ptr_src = src;
    if (ptr_dest > ptr_src && ptr_dest < ptr_src + n)
    {
        ptr_dest += n - 1;
        ptr_src += n - 1;
        while (i < n)
        {
            *ptr_dest = *ptr_src;
            ptr_dest--;
            ptr_src--;
            i++;
        }
    }
    else
    {
        while (i < n)
        {
            *ptr_dest = *ptr_src;
            ptr_dest++;
            ptr_src++;
            i++;
        }
    }
    return (dest);
}


#include <stdio.h>  // Library used in main for testing purposes
#include <string.h> // For comparison with standard memmove

int main(void)
{
    // Test case: Non-overlapping regions
    char str1[] = "Hello, world!";
    char dest1[20];
    ft_memmove(dest1, str1, strlen(str1) + 1);
    printf("ft_memmove result (non-overlapping): %s\n", dest1);  // Expected: Hello, world!

    // Test case: Overlapping regions (src before dest)
    char str2[] = "Overlap Test";
    ft_memmove(str2 + 5, str2, 7);
    printf("ft_memmove result (overlapping, src < dest): %s\n", str2);  // Expected: OverlaOverlap

    // Test case: Overlapping regions (dest before src)
    char str3[] = "Overlap Test";
    ft_memmove(str3, str3 + 5, 7);
    printf("ft_memmove result (overlapping, dest < src): %s\n", str3);  // Expected: Testst

    // Test case: Compare with standard memmove
    char str4[] = "Standard memmove";
    memmove(str4 + 8, str4, 7);
    printf("Standard memmove result: %s\n", str4);  // Expected: StandarStandard

    return 0;
}