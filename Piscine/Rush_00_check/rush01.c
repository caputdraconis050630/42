/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:35:32 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/06 11:42:47 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print(int x, int y, int row, int col)
{
	if ((row == 0 && col == 0) || (row == y - 1 && col == x - 1))
	{
		ft_putchar('/');
	}
	else if ((row == 0 && col == x - 1) || (row == y - 1 && col == 0))
	{
		ft_putchar('\\');
	}
	else if (row == 0 || row == y - 1 || col == 0 || col == x - 1)
	{
		ft_putchar('*');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			print(x, y, row, col);
			col += 1;
		}
		ft_putchar('\n');
		row += 1;
	}
}
