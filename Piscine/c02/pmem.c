#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void    hex_print(int np)
{
    char *hex;

    hex = "0123456789abcdef";
    write(1, &hex[np / 16], 1);
    write(1, &hex[np % 16], 1);
}

void	print_hex(char *np, int n)
{
    int idx[4];

    idx[0] = 0;
    idx[1] = 1;
    idx[2] = 16;
    while(*np)
    {
        if (idx[1] == n)
        {
            hex_print(*np);
            if ((idx[0] % 2) == 1)
            {
                ft_putchar(' ');
            }
        }
        if ((idx[0] % 16 ) == 15)
        {
            idx[1]++;
            idx[2] += 16;
        }
        idx[0]++;
        np++;
    }
}

void    ins_nl(char *arr, int n)
{
    int idx;
    int cnt;

    idx = 0;
    cnt = 1;
    while (*arr)
    {
        if (cnt == n)
        {
            if (!(*arr >=32 && *arr <= 126))
            {
                ft_putchar('.');
            }
            else
            {
                ft_putchar(*arr);
            }
        }
        if ((idx % 16) == 15)
        {
            cnt++;
        }
        idx++;
        arr++;
    }
}

void    prt_addr(unsigned long addr) {
    char temp[18];
    char *hex= "0123456789abcdef"; 
    int idx;

    idx = 15;
    while (idx >= 0)
    {
        temp[idx] = hex[addr & 0xF];
        addr >>= 4;
        idx--;
    }
    temp[16] = ':';
    temp[17] = ' ';
    write(1, temp, 18);
}

void    *ft_print_memory(void *addr, unsigned int size)
{
	char *temp;
    int idx[5];

    idx[0] = 0;
    idx[1] = 16;
    idx[2] = 1;
    temp = (char *)addr;
    idx[3] = size / 16 + 2;

    while (*temp)
    {
        if ((idx[0] % 16) == 0 && idx[2] < idx[3])
        {
            prt_addr((unsigned long)temp);

            print_hex((char *)addr, idx[2]);
            if (idx[0] == ft_strlen(temp) - 1)
                idx[0]++;
                hex_print('\0');
                while (idx[0] < idx[1] - 5 && idx[2] == idx[3] - 1)
                {
                    ft_putchar(' ');
                    idx[0]++;
                }
            ins_nl((char *)addr, idx[2]);
            if (idx[0] == ft_strlen(temp) - 1)
                idx[0]++;
                ft_putchar('.');
            ft_putchar('\n');
            
            idx[1] += 16;
            idx[2]++;
        }
        

        idx[0]++;
        temp++;
    }
    // printf(" ====== %d ====", idx[0]);
    // printf(" ====== %d ====", idx[1]);
    // printf(" ====== %d ====", idx[2]);
    // printf(" ====== %d ====", idx[3]);
    return (addr);
}

int main() {
    char *mot = "Bonjour les aminches\t\n\tc\t est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
    ft_print_memory(mot,92);
    // print_hex(mot, 0);
    // ft_putchar('\n');
    // print_hex(mot, 1);
    // ft_putchar('\n');
    // print_hex(mot, 2);
    // hex_addr(mot);
    // printf("hex_addr %p: %s", hex_addr(&mot[0]), hex_addr(mot));

    // ins_nl(mot);
    // prt_addr(mot[0]);

    // char *temp;

    // temp = "asdasd";

    // char *a = "Hello World";
    // char b[] = "Donkey kong";
    
    // ft_strncpy(temp, mot, 16);
    // printf("%s", temp);


    return 0;
}