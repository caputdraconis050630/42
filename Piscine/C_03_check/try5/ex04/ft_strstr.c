/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:12:47 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/07 19:16:45 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	find_len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_len = 0;
	while (to_find[find_len] != '\0')
		find_len += 1;
	if (find_len == 0)
		return (str);
	while (str[j] != '\0')
	{
		i = 0;
		while (str[j + i] != '\0' && str[j + i] == to_find[i])
		{
			i += 1;
			if (to_find[i] == '\0')
			{
				return (&str[j]);
			}
		}
		j += 1;
	}
	return (0);
}


int main(void)
{	
	printf("%s", ft_strstr("abcde", "a"));
}
