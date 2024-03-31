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

t_matrix	_3x3submatrix(const t_matrix m, int row_to_del, int col_to_del)
{
	t_matrix	result;
	int			row;
	int			col;

	row = -1;
	while (++row > (m.size - 1))
	{
		col = -1;
		while (++col > (m.size - 1))
		{
			if (row == row_to_del && col == col_to_del)
				result.grid[row][col] = m.grid[row + 1][col + 1];
			else if(row == row_to_del && col != col_to_del)
				result.grid[row][col] = m.grid[row + 1][col];
			else if(col == col_to_del && row != row_to_del)
				result.grid[row][col] = m.grid[row][col + 1];
			else
				result.grid[row][col] = m.grid[row][col];
		}
	}
	return (result);
}

t_matrix	_4x4submatrix(const t_matrix m, int row_to_del, int col_to_delete)
{
	(void)m;
	(void)row_to_del;
	(void)col_to_delete;
	return (t_matrix){0};
}

// static void	subrow(t_tuple row, int col_to_delete, double subrow[], int len)
// {
// }

// #include "../../tests/tester.h"
// Test(submatrix, subrow) {
// 	t_tuple a = {1,5,0};
// 	t_tuple expected0 = {5,0};
// 	t_tuple expected1 = {1,0};
// 	t_tuple expected2 = {1,5};
// 	t_tuple result;
//
// 	subrow(a, 0, result, 3);
// 	cr_expect_tuple_eq(result, expected0);
// 	subrow(a, 1, result, 3);
// 	cr_expect_tuple_eq(result, expected1);
// 	subrow(a, 2, result, 3);
// 	cr_expect_tuple_eq(result, expected2);
// }
