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

// static void	subrow(t_tuple row, int col_to_delete, double subrow[], int n);

t_matrix	_submatrix(const t_matrix m, int row_to_del, int col_to_del)
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
		if (row != row_to_del && col != col_to_del)
			++res_row;
		while (++col < m.size)
		{
			if (row == row_to_del || col == col_to_del)
				continue ;
			submatrix.grid[res_row][++res_col] = m.grid[row][col];
		}
	}
	submatrix.size = m.size - 1;
	return (submatrix);
}
