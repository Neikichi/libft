#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    const unsigned char *ptrs1 = (const unsigned char *)s1;
    const unsigned char *ptrs2 = (const unsigned char *)s2;

    i = 0;
    while (i < n)
    {
        if (*ptrs1 != *ptrs2)
            return (*ptrs1 - *ptrs2);
        i++;
        ptrs1++;
        ptrs2++;
    }
    return (0);
}