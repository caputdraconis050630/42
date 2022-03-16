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

	while (src[j] != '\0' && j < size)
	{
		dest[j] = src[j];
		j += 1;
	}
	dest[j] = '\0';
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (src[index] != '\0' && index < n)
	{
		dest[index] = src[index];
		index += 1;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index += 1;
	}
	return (dest);
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
	if (dest_len >= size)
		return (dest_len + src_len);
	if (src_len < size - dest_len)
	{
		strlcpy(dest + dest_len, src, src_len + 1);
	}
	else
	{
		strlcpy(dest + dest_len, src, size - dest_len);
	}
	return (dest_len + src_len);
}
