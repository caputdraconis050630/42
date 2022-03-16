/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:58:18 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/16 17:24:11 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_size(int n)
{
	size_t	size;

	size = 1;
	if (n < 0)
	{
		size += 1;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		size += 1;
	}
	return (size);
}

static void	process_itoa(char *dst, int n, size_t len)
{
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		dst[--len] = ((n % 10) + '0');
		n /= 10;
	}
	dst[len - 1] = n + '0';
}

static void	process_min(char *dst)
{
	dst[0] = '-';
	dst[1] = '2';
	dst[2] = '1';
	dst[3] = '4';
	dst[4] = '7';
	dst[5] = '4';
	dst[6] = '8';
	dst[7] = '3';
	dst[8] = '6';
	dst[9] = '4';
	dst[10] = '8';
	dst[11] = '\0';
}

char	*ft_itoa(int n)
{
	char	*dst;
	size_t	len;

	len = 0;
	if (n == -2147483648)
	{
		dst = (char *)malloc(sizeof(char) * 12);
		if (!dst)
			return (0);
		process_min(dst);
	}
	else
	{
		len = get_size(n);
		dst = (char *)malloc(sizeof(char) * (len + 1));
		if (!dst)
			return (0);
		if (n < 0)
			dst[0] = '-';
		dst[len] = '\0';
		process_itoa(dst, n, len);
	}
	return (dst);
}
