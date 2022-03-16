/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:48:03 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/19 18:58:58 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_to_int(char *nbr, char *base_from)
{
	int	ans;
	int	i;
	int	j;

	i = -1;
	while (nbr[++i])
	{
		j = 0;
		while (j < ft_strlen(base_from))
		{
			if (base_from[j] == nbr[i])
			{
				ans = ans * ft_strlen(base_from) + j;
				break ;
			}
			j += 1;
		}
		if (j == ft_strlen(base_from))
			return (ans);
	}
	return (ans);
}

void	int_to_base(int ans, char *base_to, char *ft, int *i)
{
	if (ans >= ft_strlen(base_to))
		int_to_base(ans / ft_strlen(base_to), base_to, ft, i);
	ft[*i] = base_to[ans % ft_strlen(base_to)];
	*i += 1;
}
