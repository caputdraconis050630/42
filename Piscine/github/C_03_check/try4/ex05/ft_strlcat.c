/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:17:43 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/07 14:22:06 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (src[j] != '\0' && j < (size - 1))
	{
		dest[j] = src[j];
		j += 1;
	}
	dest[j] = '\0';
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dest[dest_len] != '\0')
		dest_len += 1;
	while (src[src_len] != '\0')
		src_len += 1;
	if (size == 0)
		return (src_len);
	if (dest_len >= size)
		return (dest_len + size);
	else
	{
		ft_strlcpy(dest + dest_len, src, size - dest_len);
	}
	return (dest_len + src_len);
}
