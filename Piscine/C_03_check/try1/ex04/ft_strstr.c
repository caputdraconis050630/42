/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:12:47 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/06 21:20:59 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	find_len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_len = 0;
	while (to_find[find_len] != '\0')
		find_len += 1;
	while (str[j] != '\0')
	{
		while (i < find_len)
		{
			if (str[j + i] == '\0' || str[j + i] != to_find[i])
				break ;
			i += 1;
			if (i == find_len)
			{
				return (&str[j]);
			}
		}
		i = 0;
		j += 1;
	}
	return (0);
}
