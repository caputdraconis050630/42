/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:43:15 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/16 17:52:58 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*ft;
	int	i;

	i = 0;
	len = max - min;
	if (len <= 0)
		return (0);
	ft = (int *)malloc(sizeof(int) * len);
	if (!ft)
		return (0);
	while (min < max)
	{
		ft[i] = min;
		min += 1;
		i += 1;
	}
	return (ft);
}
