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
	if (find_len == 0)
		return (str);
	while (str[j] != '\0')
	{
		i = 0;
		while (str[j + i] != '\0' && str[j + i] == to_find[i])
		{
			i += 1;
			if (to_find[i] == '\0')
			{
				return (&str[j]);
			}
		}
		j += 1;
	}
	return (0);
}
