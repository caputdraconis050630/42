/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:46:05 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/15 17:13:34 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*preprocess_str(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i += 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i += 1;
	}
	return (&str[i]);
}

int	check_base(char *base)
{
	int	len;
	int	i;

	len = 0;
	while (base[len])
	{
		i = 0;
		if (base[len] == '+' || base[len] == '-' || base[len] == '\t'
			|| base[len] == '\n' || base[len] == '\v'
			|| base[len] == '\f' || base[len] == '\r'
			|| base[len] == ' ')
			return (1);
		while (i < len)
		{
			if (base[i] == base[len])
				return (1);
			i += 1;
		}
		len += 1;
	}
	if (len <= 1)
		return (1);
	return (0);
}

int	get_len(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len += 1;
	return (len);
}

int	is_there(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
	{
		i += 1;
	}
	if (base[i] == c)
		return (1);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	int			i;
	int			j;
	int			len;
	long long	ans;

	sign = 1;
	ans = 0;
	i = 0;
	len = get_len(base);
	str = preprocess_str(str, &sign);
	if (check_base(base))
		return (0);
	while (str[i] && is_there(base, str[i]))
	{
		j = 0;
		while (str[i] != base[j])
			j += 1;
		if (str[i] == base[j])
			ans = ans * len + j;
		else
			return (0);
		i += 1;
	}
	return (sign * ans);
}
