/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:43:07 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/15 18:43:09 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*ft;

	len = 0;
	i = 0;
	while (src[len])
		len += 1;
	ft = (char *)malloc(sizeof(char) * (len + 1));
	if (!ft)
		return (0);
	while (i < len)
	{
		ft[i] = src[i];
		i += 1;
	}
	ft[i] = '\0';
	return (ft);
}
