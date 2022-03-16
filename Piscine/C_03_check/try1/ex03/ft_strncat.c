/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:08:48 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/06 21:20:10 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	index;
	int	src_index;

	index = 0;
	src_index = 0;
	while (dest[index] != '\0')
	{
		index += 1;
	}
	while (src[src_index] != '\0' && src_index < nb)
	{
		dest[index + src_index] = src[src_index];
		src_index += 1;
	}
	dest[src_index] = '\0';
	return (dest);
}
