/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:03:13 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/08 20:39:58 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	src_index;

	dest_len = 0;
	src_index = 0;
	while (dest[dest_len] != '\0')
	{
		dest_len += 1;
	}
	while (src[src_index] != '\0')
	{
		dest[dest_len + src_index] = src[src_index];
		src_index += 1;
	}
	dest[dest_len + src_index] = '\0';
	return (dest);
}
