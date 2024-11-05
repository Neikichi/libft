#include "libft.h"

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