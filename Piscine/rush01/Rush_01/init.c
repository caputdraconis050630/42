/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:53:22 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/13 14:27:53 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_arr(int Map[6][6], int dup_chk_arr[9][5])
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 1;
		while (j < 5)
		{
			dup_chk_arr[i][j] = 0;
			j += 1;
		}
		i += 1;
	}
	i = 0;
	j = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
			Map[i][j++] = 0;
		i += 1;
	}
}

void	set_map_init(char **argv, int Map[6][6])
{
	Map[0][1] = argv[1][0];
	Map[0][2] = argv[1][2];
	Map[0][3] = argv[1][4];
	Map[0][4] = argv[1][6];
	Map[5][1] = argv[1][8];
	Map[5][2] = argv[1][10];
	Map[5][3] = argv[1][12];
	Map[5][4] = argv[1][14];
	Map[1][0] = argv[1][16];
	Map[2][0] = argv[1][18];
	Map[3][0] = argv[1][20];
	Map[4][0] = argv[1][22];
	Map[1][5] = argv[1][24];
	Map[2][5] = argv[1][26];
	Map[3][5] = argv[1][28];
	Map[4][5] = argv[1][30];
	return ;
}

int	chk_error_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (!(argv[1][i] >= '1' && argv[1][i] <= '4'))
				return (0);
		}
		else
		{
			if (argv[1][i] != ' ')
				return (0);
		}
		i += 1;
	}
	return (1);
}