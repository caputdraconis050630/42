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

int row_up_chk(int Map[6][6])
{
	int i;
	int j;
	int cnt;
	double max;

	i = 1;

	while (i <= 4)
	{
		cnt = 1;
		j = 2;
		max = Map[1][i];
		while (j <= 4)
		{
			if (max <= (double)Map[j][i] / j)
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

int row_down_chk(int Map[6][6])
{
	int i;
	int j;
	int cnt;
	double max;

	i = 1;
	while (i <= 4)
	{
		cnt = 1;
		max = Map[4][i];
		j = 3;
		while (j >= 1)
		{
			if (max <= (double)Map[j][i] / (5 - j))
			{
				max = (double)Map[j][i] / (5 - j);
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

int col_left_chk(int Map[6][6])
{
	int i;
	int j;
	int cnt;
	double max;

	i = 1;
	while (i <= 4)
	{
		cnt = 1;
		max = Map[i][1];
		j = 2;
		while (j <= 4)
		{
			if (max <= (double)Map[i][j] / j)
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

int col_right_chk(int Map[6][6])
{
	int i;
	int j;
	int cnt;
	double max;

	i = 1;
	while (i <= 4)
	{
		cnt = 1;
		max = Map[i][4];
		j = 3;
		while (j >= 1)
		{
			if (max <= (double)Map[i][j] / (5 - j))
			{
				max = (double)Map[i][j] / (5 - j);
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

int total_chk(int Map[6][6])
{
	if (!row_up_chk(Map))
		return (0);
	if (!row_down_chk(Map))
		return (0);
	if (!col_left_chk(Map))
		return (0);
	if (!col_right_chk(Map))
		return (0);
	return (1);
}
