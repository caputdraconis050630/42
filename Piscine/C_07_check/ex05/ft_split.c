/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:40:42 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/17 11:02:30 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len += 1;
	return (len);
}

char	*ft_strdup(char *src, char *end)
{
	char	*dest;
	char	*temp;
	int		len;

	temp = src;
	len = 0;
	while (temp < end)
		len += 1;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	temp = dest;
	while (src < end)
	{
		*temp = *src;
		temp += 1;
		src += 1;
	}
	*temp = '\0';
	return (dest);
}

void	process(char **ft, char *str, char *charset, int len)
{
	char	*temp;
	char	dup;

	temp = str;
	while (ft_strstr(temp, charset))
	{
		temp = ft_strstr(temp, charset);
		dup = ft_strdup(str, temp);
		if (dup)
		{
			*strs = dup;
			strs += 1;
		}
		temp += len;
		str = temp;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ft;
	char	*temp;
	int		len;
	int		splits;

	len = ft_strlen(charset);
	temp = str;
	splits = 0;
	while (ft_strstr(temp, charset) != 0)
	{
		temp = ft_strstr(temp, charset);
		temp += len;
		splits += 1;
	}
	ft = (char **)malloc(sizeof(char *) * (2 + splits));
	if (!ft)
		return (0);
	process(ft, str, charset, len);
	return (strs);
}	
