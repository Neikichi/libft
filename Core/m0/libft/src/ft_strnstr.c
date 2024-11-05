#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    if (!*little)
        return ((char *)big);
    while (big[i] && i < len)
    {
        j = 0;
        if (little[j] == big[i])
        {
            while (little[j] && big[i + j] && (i + j) < len)
            {
                if (big[i + j] != little[j])
                    break;
                j++;
            }
            if (!little[j])
                return ((char *)big + i);
        }
        i++;
    }
    return (NULL);
}