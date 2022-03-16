/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:03:13 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/07 09:10:42 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	src_index;

	index = 0;
	src_index = 0;
	while (dest[index] != '\0')
	{
		index += 1;
	}
	while (src[src_index] != '\0')
	{
		dest[index + src_index] = src[src_index];
		src_index += 1;
	}
	dest[src_index] = '\0';
	return (dest);
}
