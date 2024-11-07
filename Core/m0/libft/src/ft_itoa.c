#include "libft.h"

static int ft_countdigits(long int n);
static char *ft_itoa_ex(int n);

char *ft_itoa(int n)
{
  if (n == 2147483647)
    return (ft_strdup("2147483647"));
  if (n == -2147483648)
    return (ft_strdup("-2147483648"));
  if (n == 0)
    return (ft_strdup("0"));
  return (ft_itoa_ex(n));
}

static char *ft_itoa_ex(int n)
{
  int neg;
  int size;
  char *buffer;

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

static int ft_countdigits(long int n)
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
