#include "libft.h"
#include <stdio.h>

int main() {
    char *test = ft_calloc(5, sizeof(char));
    if (test) {
        printf("ft_calloc works\n");
    } else {
        printf("ft_calloc failed\n");
    }
    return 0;
}