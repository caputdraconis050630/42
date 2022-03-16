/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:34:57 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/20 12:40:19 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i += 1;
	}
	return (0);
}

void	skip_sep(char *str, char *charset, int *i)
{
	while (str[*i] && is_sep(str[*i], charset))
		(*i) += 1;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	split = (char **)malloc(sizeof(char *) * 256);
	if (!split)
		return (0);
	skip_sep(str, charset, &i);
	while (str[i])
	{
		j = 0;
		split[k] = (char *)malloc(sizeof(char) * 4096);
		if (!(split[k]))
			return (0);
		while (!is_sep(str[i], charset) && str[i])
			split[k][j++] = str[i++];
		skip_sep(str, charset, &i);
		split[k++][j] = '\0';
	}
	split[k] = 0;
	return (split);
}
