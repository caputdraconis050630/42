/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:08:19 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/19 14:08:20 by guntkim          ###   ########.fr       */
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
