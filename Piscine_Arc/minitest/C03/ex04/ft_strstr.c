/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:08:03 by vlow              #+#    #+#             */
/*   Updated: 2024/09/02 20:07:07 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	idx;
	int	cnt;

	idx = 0;
	if (*to_find == '\0')
		return (str);
	while (str[idx] != '\0')
	{
		cnt = 0;
		while (to_find[cnt] == str[idx + cnt])
		{
			if (to_find[cnt + 1] == '\0')
			{
				return (str + idx);
			}
			cnt++;
		}
		idx++;
	}
	return (0);
}
