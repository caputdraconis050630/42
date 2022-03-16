/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:58:08 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/15 16:23:50 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_nb(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i += 1;
	}
	return (-1);
}

long long	process_str(char *str, char *base, int base_len)
{
	long long	ans;
	int			sign;
	int			i;
	int			j;

	sign = 1;
	i = 0;
	j = 0;
	ans = 0;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i += 1;
	}
	while (str[i] != '\0')
	{
		ans = (ans * base_len) + get_nb(str[i], base);
		i += 1;
	}
	return (sign * ans);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	j;

	base_len = 1;
	while (base[base_len])
	{
		j = 1;
		if (base[base_len] == '+' || base[base_len] == '-')
			return (0);
		while (base[base_len + j] != '\0')
		{
			if (base[base_len + j] == base[base_len])
				return (0);
			j += 1;
		}
		base_len += 1;
	}
	if (base_len <= 1)
		return (0);
	j = 0;
	while (str[j] != '\0' && (str[j] == ' ' || str[j] == '\t' || str[j] == '\r'
			|| str[j] == '\n' || str[j] == '\v' || str[j] == '\f'))
		j += 1;
	return (process_str(&str[j], base, base_len));
}
