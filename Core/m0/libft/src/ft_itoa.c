#include "libft.h"

static int ft_countdigits(int n);

char *ft_itoa(int n)
{
  int neg;
  int size;
  char *buffer;

  size = 0;
  neg = 0;
  if (n < 0)
  {
    n = -n;
    neg = 1;
  }
  size = ft_countdigits(n) + neg; 
  buffer = malloc(sizeof(char) * (size + 1));
  if (!buffer)
    return (NULL);
  if (neg)
    buffer[0] = '-';
  buffer[size + 1] = '\0';
  while (size != neg)
  {
    buffer[size] = (n % 10) + '0';
    size--;
    n /= 10;
  }
  return (buffer);
}

static int ft_countdigits(int n)
{
  int count;

  count = 0;
  while (n != 0)
  {
    n /= 10;
    count++;
  }
  return (count);
}
