/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:43:29 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/15 18:43:30 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	bridge(char *ft, int *j, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		ft[*j] = sep[i++];
		*j += 1;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ft;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	ft = (char *)malloc(sizeof(char) * 4096);
	while (i < size)
	{
		k = 0;
		while (strs[i][k])
		{
			ft[j] = strs[i][k++];
			j += 1;
		}
		if (i != size - 1)
			bridge(ft, &j, sep);
		i += 1;
	}
	ft[j] = '\0';
	return (ft);
}
