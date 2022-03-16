/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:30:22 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/21 08:30:24 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ft;

	i = 0;
	ft = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		ft[i] = (*f)(tab[i]);
		i += 1;
	}
	return (ft);
}
