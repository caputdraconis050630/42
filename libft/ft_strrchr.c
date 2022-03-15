/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:35:52 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/15 18:21:30 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len])
		len += 1;
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
		{
			return ((char *)&s[len]);
		}
		len -= 1;
	}
	return (0);
}
