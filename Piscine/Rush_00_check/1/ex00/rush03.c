/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjpar <hyunjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:36:08 by hyunjpar          #+#    #+#             */
/*   Updated: 2022/02/06 18:37:10 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	choose_char(int i, int j, int rows, int cols)
{
	if (i == 0)
	{
		if (j == 0)
			return (1);
		if (j == cols - 1)
			return (2);
		return (5);
	}
	if (i == rows - 1)
	{
		if (j == 0)
			return (3);
		if (j == cols - 1)
			return (4);
		return (6);
	}
	if (j == 0)
		return (6);
	if (j == cols - 1)
		return (6);
	return (0);
}

void	rush_base(char *chrs, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			ft_putchar(chrs[choose_char(i, j, rows, cols)]);
			j += 1;
		}
		ft_putchar('\n');
		i += 1;
	}
}

void	rush(int x, int y)
{
	char	chars[10];

	chars[0] = ' ';
	chars[1] = 'A';
	chars[2] = 'C';
	chars[3] = 'A';
	chars[4] = 'C';
	chars[5] = 'B';
	chars[6] = 'B';
	if (x <= 0 || y <= 0)
		return ;
	rush_base(chars, y, x);
}
