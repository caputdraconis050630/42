/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:29:50 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/19 14:37:12 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int min, int max)
{
	int	*range;
	int	*buffer;

	if (min >= max)
		return (0);
	range = (int *)malloc(sizeof(min) * (max - min));
	if (! range)
		return (0);
	buffer = range;
	while (min < max)
		*buffer++ = min++;
	return (range);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_rrange(min, max);
	if (min >= max)
		return (0);
	if (!*range)
		return (-1);
	return (max - min);
}
