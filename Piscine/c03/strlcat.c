#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	ct;

	ct = 0;
	while (*str)
	{
		str++;
		ct++;
	}
	return (ct);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	idx;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	idx = 0;
	while (src[idx] != '\0' && dest_len + idx < size - 1)
	{
		dest[dest_len + idx] = src[idx];
		idx++;
	}
	dest[dest_len + idx] = '\0';
	return (dest_len + src_len);
}

int main(void)
{
    char c1[] = "Hello World ego";
    char c2[] = "World";
	char c11[] = "Hello World ego";
    char c22[] = "World";

	printf("%u\n", ft_strlcat(c1,c2, 4));
    printf("%lu\n", strlcat(c11, c22, 4));
    return 0;
}