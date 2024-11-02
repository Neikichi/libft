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

void ft_putchar(char c)
{
    write(1,&c,1);
}

void	print_hex(int np)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[np / 16], 1);
	write(1, &hex[np % 16], 1);
}

void    ft_putstr_non_printable(char *str)
{
    char	*hex;

	hex = "0123456789abcdef";
    while (*str)
    {
        if (!(*str >= 32 && *str <= 126))
        {
            ft_putchar('\\');
            ft_putchar(hex[*str / 16]);
            ft_putchar(hex[*str % 16]);
            str++;
        }
        ft_putchar(*str);
        str++;
    }
}


int main(void)
{
    char a[14] = "Hello\t World";
    // char b[] = "Donkey Kong babeh";

    ft_putstr_non_printable(a);
    // printf("len of b1: %d\n", lenchk(b));
    // print_hex('\n');
    // printf("UI + %u\n", ft_strlcpy(b, a, 10));
    // printf("Sizeof %d\n", (int)sizeof(b));
    // for (int i; i < lenchk(a); i++)
    // printf("len of b: %d\n", lenchk(b));
    // printf("print b: %s\n", b);
    // for (size_t i = 0; i <= sizeof(b); i++) {
    //     printf("Index %zu: %02x\n", i, (unsigned char)b[i]);
    // }
  
    return (0);
}
