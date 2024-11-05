#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *ptr = s;

    i = 0;
    while (i < n)
    {
        *ptr = (unsigned char)c;
        ptr++;
        i++;
    }
    return (s);
}