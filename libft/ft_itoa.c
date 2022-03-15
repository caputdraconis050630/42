/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:58:18 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/15 18:24:31 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_nb_size(unsigned int nb)
{
	size_t	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1);
}

char	*ft_itoa(int nbr)
{
	char			*str;
	unsigned int	nb;
	unsigned int	index;
	unsigned int	size;

	if (nbr < 0)
		nb = (unsigned int)(nbr * -1);
	else
		nb = (unsigned int)nbr;
	size = (unsigned int)get_nb_size(nb);
	index = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1 + (nbr < 0 ? 1 : 0)))))
		return (0);
	if (nbr < 0 && (str[index] = '-'))
		size++;
	index = size - 1;
	while (nb >= 10)
	{
		str[index--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[index] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
