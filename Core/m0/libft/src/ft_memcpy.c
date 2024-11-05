#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *ptr_dest;
    const unsigned char *ptr_src;
    size_t i;

    i = 0;
    ptr_dest = dest;
    ptr_src = src;
    while (i < n)
    {
        *ptr_dest = *ptr_src;
        ptr_dest++;
        ptr_src++;
        i++;
    }
    return (dest);
}