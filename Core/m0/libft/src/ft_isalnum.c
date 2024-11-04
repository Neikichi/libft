#include "libft.h"

int ft_isalnum(int c)
{
    if (ft_alpha(c) && ft_isdigit(c))
        return (1);
    return (0);
}