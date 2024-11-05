
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	c;
	int	amt;
	int	len;
	int	len_two;

	c = 0;
	amt = 0;
	len = ft_strlen(s1);
	len_two = ft_strlen(s2);
	while (c < len || c < len_two)
	{
		amt = amt + (s1[c] - s2[c]);
		if (amt != 0)
			return (amt);
		c++;
	}
	return (0);
}

void	ft_bubble_sort(int count, char *arr[])
{
	int		sw;
	int		y[2];
	char	*temp;

	sw = 0;
	while (sw == 0)
	{
		sw = 1;
		y[0] = 2;
		y[1] = y[0] - 1;
		while (y[0] < count)
		{
			if (ft_strcmp(arr[y[1]], arr[y[0]]) > 0)
			{
				temp = arr[y[1]];
				arr[y[1]] = arr[y[0]];
				arr[y[0]] = temp;
				sw = 0;
			}
			y[0]++;
			y[1]++;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	y;
	int	x;

	y = 1;
	ft_bubble_sort(argc, argv);
	while (y < argc)
	{
		x = 0;
		while (argv[y][x] != '\0')
		{
			ft_putchar(argv[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}