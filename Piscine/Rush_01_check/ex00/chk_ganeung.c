/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_ganeung.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:20:26 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/12 19:19:21 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int row_up_chk(int **Map)
{
	int		i;
	int		j;
	int		cnt;
	double	max;

	i = 1;
	while (i <= 4)
	{
		cnt = 1;
		max = Map[1][i];
		j = 2;
		while (j <= 4)
		{
			if (max < (double)Map[j][i] / j)
			{
				max = (double)Map[j][i] / j;
				cnt += 1;
			}
			j += 1;
		}
		if (Map[0][i] != cnt)
			return (0);
		i += 1;
	}
	return (1);
}

int	row_down_chk(int **Map)
{
	int		i;
	int		j;
	int		cnt;
	double	max;

	i = 1;
	while (i <= 4)
	{
		cnt = 1;
		max = Map[4][i];
		j = 3;
		while (j > 0)
		{
			if (max <= (double)Map[j][i] / (4 - j))
			{
				max = (double)Map[j][i] / (4 - j);
				cnt += 1;
			}
			j -= 1;
		}
		if (Map[5][i] != cnt)
			return (0);
		i += 1;
	}
	return (1);
}

int	col_left_chk(int **Map)
{
	int		i;
	int		j;
	int		cnt;
	double	max;

	i = 1;
	while (i <= 4)
	{
		cnt = 1;
		max = Map[1][i];
		j = 2;
		while (j <= 4)
		{
			if (max < (double)Map[i][j] / j)
			{
				max = (double)Map[i][j] / j;
				cnt += 1;
			}
			j += 1;
		}
		if (Map[i][0] != cnt)
			return (0);
		i += 1;
	}
	return (1);
}

int col_right_chk(int **Map)
{
int		i;
	int		j;
	int		cnt;
	double	max;

	i = 1;
	while (i <= 4)
	{
		cnt = 1;
		max = Map[4][i];
		j = 3;
		while (j > 0)
		{
			if (max < (double)Map[i][j] / (4 - j))
			{
				max = (double)Map[i][j] / (4 - j);
				cnt += 1;
			}
			j -= 1;
		}
		if (Map[i][5] != cnt)
			return (0);
		i += 1;
	}
	return (1);	
}
