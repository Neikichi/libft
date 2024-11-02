#include <stdio.h>
#include <unistd.h>

int	lenchk(char *arr)
{
	int	len;

	len = 0;
	while (*arr)
	{
		arr++;
		len++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int idx;

	idx = 0;
    if (n == 0)
        return (lenchk(src));
	while (idx < n)
    {
        if (src[idx] != '\0' && idx < n - 1)
        {
            dest[idx] = src[idx];
            idx++;
        }
    }
    dest[idx] = '\0';
    return (lenchk(src));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[count] != '\0' && count < (size - 1))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (ft_strlen(src));
}

int main(void)
{
    char a[] = "Hello World";
    char b[] = "";
    // printf("len of b1: %d\n", lenchk(b));

    printf("UI + %u\n", ft_strlcpy(b, a, 10));
    // printf("Sizeof %d\n", (int)sizeof(b));
    // for (int i; i < lenchk(a); i++)
    // printf("len of b: %d\n", lenchk(b));
    // printf("print b: %s\n", b);
    // for (size_t i = 0; i <= sizeof(b); i++) {
    //     printf("Index %zu: %02x\n", i, (unsigned char)b[i]);
    // }
  
    return (0);
}
