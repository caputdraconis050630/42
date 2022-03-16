/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:58:28 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/07 09:33:41 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	index;

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

int main(void)
{	
	char a;
	char *dest = &a;
	ft_strncpy(dest, "hoit", 7);
	printf("%s", dest);
}
