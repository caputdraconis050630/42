/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:44:20 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/06 09:47:37 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init(char *arr)
{
	arr[0] = '0';
	arr[1] = '1';
	arr[2] = '2';
	arr[3] = '3';
	arr[4] = '4';
	arr[5] = '5';
	arr[6] = '6';
	arr[7] = '7';
	arr[8] = '8';
	arr[9] = '9';
	arr[10] = 'a';
	arr[11] = 'b';
	arr[12] = 'c';
	arr[13] = 'd';
	arr[14] = 'e';
	arr[15] = 'f';
}

void	hex(char c)
{
	char	*hex_arr;

	init(hex_arr);
	if (c >= 16)
	{
		write(1, &hex_arr[c / 16], 1);
	}
	write(1, &hex_arr[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 32 && str[index] <= 126)
		{
			write(1, &str[index], 1);
		}
		else
		{
			write(1, "\\", 1);
			hex(str[index]);
		}
		index += 1;
	}
}