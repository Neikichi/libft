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

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	if (lenchk(dest) < lenchk(src))
	{
		return (0);
	}
	else
	{
		idx = 0;
		while (idx < lenchk(src))
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	return (dest);
}

int main(void)
{
    char a[12] = "Hello World";
    char b[50] = "Donkey Kong";

    ft_strcpy(b, a);
    // for (int i; i < lenchk(a); i++)
    printf("print b: %s\n", b);
    for (size_t i = 0; i < sizeof(b); i++) {
        printf("Index %zu: %02x\n", i, (unsigned char)b[i]);
    }
  
  return 0;
}
