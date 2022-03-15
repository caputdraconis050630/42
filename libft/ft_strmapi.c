/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:56:25 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/15 18:47:37 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*dst;

	len = 0;
	i = 0;
	while (s[len])
		len += 1;
	dst = (char *)malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		dst[i] = f(i, s[i]);
		i += 1;
	}
	return (dst);
}
