/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:47:42 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/16 17:43:01 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_floors(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 1;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i += 1;
		while (s[i] && s[i] != c)
			i += 1;
		if (s[i - 1] != c)
			cnt += 1;
	}
	return (cnt);
}

static size_t	get_rooms(char const *s, char c)
{
	size_t	ret;

	ret = 0;
	while (s[ret] && s[ret] != c)
		ret += 1;
	return (ret);
}

static void	free_all(char **dst)
{
	size_t	i;

	i = 0;
	while (dst[i])
		free(dst[i++]);
	free(dst);
}

static size_t	process_split(char **dst, char const *s, char c)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	while (s[i] && s[i] == c)
		i += 1;
	while (s[i])
	{
		dst[t] = (char *)malloc(sizeof(char) * get_rooms(&s[i], c) + 1);
		if (!dst[t])
			return (0);
		ft_strlcpy(dst[t], &s[i], get_rooms(&s[i], c) + 1);
		i += get_rooms(&s[i], c);
		while (s[i] && s[i] == c)
			i += 1;
		t += 1;
	}
	dst[t] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	dst = (char **)malloc(sizeof(char *) * get_floors(s, c) + 1);
	if (!dst)
		return (0);
	if (!process_split(dst, s, c))
	{
		free_all(dst);
		return (0);
	}
	return (dst);
}
