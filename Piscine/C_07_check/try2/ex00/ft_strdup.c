/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:07:57 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/19 14:08:00 by guntkim          ###   ########.fr       */
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
