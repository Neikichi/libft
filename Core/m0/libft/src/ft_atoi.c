/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:10:15 by vlow              #+#    #+#             */
/*   Updated: 2024/11/06 13:10:31 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// add more library if needed in the function except main
static int ft_isspace(int c);

// provide a brief description simple for each of the via comment below format.
/// @brief ASCII to INTEGER conversion
/// @param nptr takes in strings or char
/// @return 0 if fail or the digits in INT
int ft_atoi(const char *nptr)
{
  int neg;
  int amt;

  amt = 0;
  neg = 1;
  while (ft_isspace(*nptr))
  {
    nptr++;
  }
  if (*nptr == '-' || *nptr == '+')
  {
    if (*nptr == '-')
      neg = -1;
    nptr++;
  }
  while (ft_isdigit(*nptr))
  {
    amt = amt * 10 + (*nptr - '0');
    nptr++;
  }
  return amt * neg;
}

static int ft_isspace(int c)
{
    if (c == 32 || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

#include <stdio.h>  // Library used for test cases
int main(void)
{
  // Edge test case
  const char *test_case1 = "   \t\n  -12345abc";
  printf("ft_atoi(\"%s\") = %d\n", test_case1, ft_atoi(test_case1));

  // Compare with original atoi function from standard library
  printf("atoi(\"%s\") = %d\n", test_case1, atoi(test_case1));

  return 0;
}
