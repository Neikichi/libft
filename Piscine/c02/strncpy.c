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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int idx;

	idx = 0;
	while (idx < (int)n)
    {
        if (src[idx] != '\0')
        {
            dest[idx] = src[idx];
            idx++;
        }
        else //(idx < (int)n)
        {
            dest[idx] = '\0';
            idx++;
        }
    }
    return (dest);
}

int main(void)
{
    char a[] = "Hello World";
    char b[3] = "Don";
    // printf("len of b1: %d\n", lenchk(b));

    ft_strncpy(b, a, 8);
    // printf("Sizeof %d\n", (int)sizeof(b));
    // for (int i; i < lenchk(a); i++)
    // printf("len of b: %d\n", lenchk(b));
    printf("print b: %s\n", b);
    for (size_t i = 0; i <= sizeof(b); i++) {
        printf("Index %zu: %02x\n", i, (unsigned char)b[i]);
    }
  
    return (0);
}
