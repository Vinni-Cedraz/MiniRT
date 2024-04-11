/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:22:41 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/07 10:08:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static _Bool	this_number_must_stay(int row, int col, int del_col,
					int del_row);
static _Bool	this_number_must_go(int row, int col, int del_col, int del_row);

t_matrix	_submatrix(const t_matrix m, int del_row, int del_col)
{
	t_matrix	submatrix;
	int			row;
	int			col;
	int			res_row;
	int			res_col;

	row = -1;
	res_row = -1;
	while (++row < m.size)
	{
		col = -1;
		res_col = -1;
		if (this_number_must_stay(row, col, del_col, del_row))
			++res_row;
		while (++col < m.size)
		{
			if (this_number_must_go(row, col, del_col, del_row))
				continue ;
			submatrix.grid[res_row][++res_col] = m.grid[row][col];
		}
	}
	submatrix.size = m.size - 1;
	return (submatrix);
}

static _Bool	this_number_must_stay(int row, int col, int del_col,
		int del_row)
{
	if (row != del_row && col != del_col)
		return (true);
	else
		return (false);
}

static _Bool	this_number_must_go(int row, int col, int del_col, int del_row)
{
	if (row == del_row || col == del_col)
		return (true);
	else
		return (false);
}
