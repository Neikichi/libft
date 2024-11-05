#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



int	is_sides(int i)
{
	int	j;

	j = 2;
	while (j < 10)
	{
		if (j * 4 == i)
		{
			return (j);
		}
		else
		{
			j ++;
		}
	}
	return (0);
}

int    num_loop(char *input, char *clean_input, int *len)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (input[i])
	{
		if (input[i] <= '9' && input[i] > '0')
		{
			clean_input[j] = input[i];
			j++;
			(*len)++;
		}
		if (j > 36)
		{
			write(1, "Error!\n", 7);
			return (0);
		}
		i++;
	}
    return (1);
}

char	extract_numbers(char *input)
{
	int		len;
	char	clean_input[37];
	int		n;

	len = 0;
	if (!(num_loop(input, clean_input, &len)))
        return (0);
	if (is_sides(len))
		n = is_sides((len));
	else
		return (0);
	return (*clean_input);
}

int main() 
{
    printf("%c",extract_numbers("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"));
    printf("%c",extract_numbers("2 4 1 4 4 3 2 1 2 3 2 3 2 5 2 6 4 4 3 2 1 3 1 2 2 3 3 5"));
}