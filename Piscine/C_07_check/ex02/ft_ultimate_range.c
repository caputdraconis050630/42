/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:43:21 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/17 08:53:43 by guntkim          ###   ########.fr       */
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

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;

	len = max - min;
	*range = ft_range(min, max);
	if (len <= 0)
		return (0);
	if (!*range)
		return (-1);
	return (len);
}
