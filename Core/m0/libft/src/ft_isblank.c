#include "libft.h"

int ft_isblank(int c)
{
    if (c == 32 || c == 9)
        return (1);
    return (0);
}