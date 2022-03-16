/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_chk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:48:36 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/13 14:48:52 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	dup_chk(int dup_chk_arr[9][5], int row_col, int line_num, int value)
{
	if (row_col == 0)
	{
		return (dup_chk_arr[line_num][value]);
	}
	else
	{
		return (dup_chk_arr[line_num + 4][value]);
	}
}

void	dup_chk_assign(int dup_chk_arr[9][5], int x, int y, int value)
{
	dup_chk_arr[x][value] = 1;
	dup_chk_arr[y + 4][value] = 1;
}

void	dup_chk_unassign(int dup_chk_arr[9][5], int x, int y, int value)
{
	dup_chk_arr[x][value] = 0;
	dup_chk_arr[y + 4][value] = 0;
}
