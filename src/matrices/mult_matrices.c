/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:30:24 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/03 11:48:35 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_col(t_matrix b, int col_idx, t_tuple col);
static void	multiply_row_by_matrix(t_tuple row, t_matrix mat, t_tuple res);

t_matrix	mult_matrices(t_matrix a, t_matrix b)
{
	t_matrix	result;

	multiply_row_by_matrix(a.row_1, b, result.row_1);
	multiply_row_by_matrix(a.row_2, b, result.row_2);
	multiply_row_by_matrix(a.row_3, b, result.row_3);
	multiply_row_by_matrix(a.row_4, b, result.row_4);
	return (result);
}

static void	multiply_row_by_matrix(t_tuple row, t_matrix mat, t_tuple res)
{
	t_tuple	col;
	int		idx;

	idx = -1;
	while (++idx < 4)
	{
		init_col(mat, idx, col);
		res[idx] = dot(row, col);
	}
}

static inline void	init_col(t_matrix b, int col_idx, t_tuple col)
{
	col[X] = b.row_1[col_idx];
	col[Y] = b.row_2[col_idx];
	col[Z] = b.row_3[col_idx];
	col[W] = b.row_4[col_idx];
}

// #include "../../tests/tester.h"
// Test(operations, init_col)
// {
// 	t_tuple		expect_col = {1, 5, 9, 13};
// 	t_matrix	matrix = {
// 		{1, 2, 3, 4},
// 		{5, 6, 7, 8},
// 		{9, 10, 11, 12},
// 		{13, 14, 15, 16}
// 	};
// 	t_tuple		col;
//
// 	init_col(matrix, 0, col);
// 	cr_expect_tuple_eq(col, expect_col);
// }
//
// Test(operations, multiply_row_by_matrix) {
// 	t_matrix a = {
// 		{1,2,3,4},
// 		{0,0,0,0},
// 		{0,0,0,0},
// 		{0,0,0,0},
// 	};
// 	t_matrix b = {
// 		{-2, 1, 2,3 },
// 		{3, 2, 1, -1},
// 		{4, 3, 6, 5},
// 		{1, 2, 7, 8}
// 	};
// 	t_tuple expected = {20, 22, 50, 48};
// 	t_tuple res;
//
// 	multiply_row_by_matrix(a.row_1, b, res);
// 	cr_expect_tuple_eq(expected, res);
// }
