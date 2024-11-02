#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char clean_input[37];
int n;

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

void	str_split(char *arr, char **rnc, int n)
{
	int	cnt;
	int	idx;

	while (*arr)
	{
		cnt = 0;
		while (*arr && cnt < 4 * n)
		{
			idx = cnt % n;
			if (cnt / n == 0)
				rnc[0][idx] = *arr;
			else if (cnt / n == 1)
				rnc[1][idx] = *arr;
			else if (cnt / n == 2)
				rnc[2][idx] = *arr;
			else
				rnc[3][idx] = *arr;
			arr++;
			cnt++;
		}
	}
}

int	strval(char **rnc, int n)
{
	int	idx;
    int sum_r;
    int sum_c;

	idx = 0;
    sum_r = ((rnc[0][idx] - '0') + (rnc[1][idx] - '0'));
    sum_c = ((rnc[2][idx] - '0') + (rnc[3][idx] - '0'));
	while (idx < n)
	{
		if (sum_r > (n + 1) || sum_c > (n + 1))
		{
			return (0);
		}
		idx++;
	}
	return (1);
}

int	str_chk(char *arr, int n)
{
    char **row_n_col;
    int     idx;
    int result;

    idx = 0;
    row_n_col = malloc(4 * 8);
    while (idx < n)
    {
        row_n_col[idx] = malloc(n * 1 + 1);
        row_n_col[idx][n + 1] = '\0';
        idx++;
    }
    
	str_split(arr, row_n_col, n);
    result = strval(row_n_col, n);
    printf("%s\n", row_n_col[0]);
    printf("%s\n", row_n_col[1]);
    printf("%s\n", row_n_col[2]);
    printf("%s\n", row_n_col[3]);
    idx = 0;
    while (idx < 4)
    {
        free(row_n_col[idx]);
        idx++;
    }
    free(row_n_col);
	return (result);
}

int extract_numbers(char *input)
{
    int i;
    int j;
    int len;
    
    i = 0;
    j = 0;
    len = 0;
    while (input[i])
    {
        if (input[i] <= '9'&& input[i] > '0')
        {
          clean_input[j] = input[i];
          j ++ ;
          len ++;
        }
        if (j > 36)
        {
            write(1, "too long", 8);
            return (0);
        }
        i++;
    }
    if (is_sides(len))
    {
        n = is_sides((len));
    }
    else
    {
        return(0);
    }
    return (1);
}

int main()
{
    // char av[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
    // int narr = 
    // extract_numbers(av);
    // str_chk(clean_input, n);
    // printf("%s\n", clean_input);
    // printf("%d\n", n);

    // str_chk(goon.clean_input, goon.len);
    // printf("%d\n", extract_numbers(av));



    // char inp[] = "4321122243211222";

    
    // char inp1[] = "35241512345321324531";  // for 5x5 grid

    // char inp2[] = "12453421532454321354";  // for 5x5 grid
    // char inp3[] = "213324442142212333342212";  // for 6x6 grid
    char inp4[] = "324516732653475463436275423245326456";  // for 6x6 grid




    // str_chk(inp, 4);
    // str_chk(inp1, 5);
    // str_chk(inp2, 5);

    // printf("%d\n", str_chk(inp, 4));
    // printf("%d\n", str_chk(inp1, 5));
    // printf("%d\n", str_chk(inp2, 5));
    // printf("%d\n", str_chk(inp3, 6));
    printf("%d\n", str_chk(inp4, 9));

    return 0;
}