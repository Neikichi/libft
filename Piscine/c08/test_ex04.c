/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keigoh <keigoh@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:04:55 by keigoh            #+#    #+#             */
/*   Updated: 2024/09/10 20:09:31 by keigoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include "ft_stock_str.h"
#include <stdio.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*strdup;
	int		count;

	count = 0;
	strdup = malloc((str_len(src) + 1) * sizeof(char));
	if (strdup != NULL)
	{
		while (src[count])
		{
			strdup[count] = src[count];
			count++;
		}
		strdup[count] = '\0';
		return (strdup);
	}
	else
		return (NULL);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					index;
	struct s_stock_str	*av_trans;

	index = 0;
	av_trans = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (av_trans == NULL)
		return (NULL);
	while (index < ac)
	{
		av_trans[index].size = str_len(av[index]);
		av_trans[index].str = av[index];
		av_trans[index].copy = ft_strdup(av[index]);
		index++;
	}
	av_trans[index].str = 0;
	return (av_trans);
}

int main(void)
{
    char *av[] = {"aa"};
    int ac = 0;
    struct s_stock_str *av_trans;
    int i = 0;
    
    av_trans = ft_strs_to_tab(ac, av);
    while (av_trans[i].str != 0)
    {
        printf("size: %i\n", av_trans[i].size);
        printf("str: %s\n", av_trans[i].str);
        printf("copy: %s\n\n", av_trans[i].copy);
        i++;
    }
}

