#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int ft_atoi(const char *nptr);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_strlcat(char *dst, const char *src, size_t size);

#endif
