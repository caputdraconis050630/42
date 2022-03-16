/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:17:43 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/09 13:50:04 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (src_len + size);
	if (dest_len > size)
		return (size + src_len);
	while ((dest_len + i + 1) < size && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i += 1;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
