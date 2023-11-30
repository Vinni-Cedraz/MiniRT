/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:24:49 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/03 16:27:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			turn_col_into_row(t_tuple col, t_tuple row);
static void			init_col(t_matrix b, int col_idx, t_tuple col);

t_matrix	transpose_matrix(t_matrix m)
{
	t_matrix	res;
	t_tuple		col;

	create_4x4_matrix(&res);
	init_col(m, COL1, col);
	turn_col_into_row(col, res.row_1);
	init_col(m, COL2, col);
	turn_col_into_row(col, res.row_2);
	init_col(m, COL3, col);
	turn_col_into_row(col, res.row_3);
	init_col(m, COL4, col);
	turn_col_into_row(col, res.row_4);
	return (res);
}

static inline void	turn_col_into_row(t_tuple col, t_tuple row)
{
	row[X] = col[X];
	row[Y] = col[Y];
	row[Z] = col[Z];
	row[W] = col[W];
}

static inline void	init_col(t_matrix b, int col_idx, t_tuple col)
{
	col[X] = b.row_1[col_idx];
	col[Y] = b.row_2[col_idx];
	col[Z] = b.row_3[col_idx];
	col[W] = b.row_4[col_idx];
}

// #include "../../tests/tester.h"
//
//
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
// Test(transpose_matrix, turn_col_into_row)
// {
// 	t_matrix m = {
// 		{1, 2, 3, 4},
// 		{4, 3, 2, 1},
// 		{9, 8, 7, 6},
// 		{6, 7, 8, 9},
// 	};
// 	t_matrix result;
// 	t_tuple col;
//
// 	init_col(m, 0, col);
// 	turn_col_into_row(col, result.row_1);
// 	t_tuple expect_row = {1, 4, 9, 6};
// 	cr_expect_tuple_eq(result.row_1, expect_row);
//
// 	init_col(m, 1, col);
// 	turn_col_into_row(col, result.row_2);
// 	t_tuple expect_row2 = {2, 3, 8, 7};
// 	cr_expect_tuple_eq(result.row_2, expect_row2);
//
// 	init_col(m, 2, col);
// 	turn_col_into_row(col, result.row_3);
// 	t_tuple expect_row3 = {3, 2, 7, 8};
// 	cr_expect_tuple_eq(result.row_3, expect_row3);
//
// 	init_col(m, 3, col);
// 	turn_col_into_row(col, result.row_4);
// 	t_tuple expect_row4 = {4, 1, 6, 9};
// 	cr_expect_tuple_eq(result.row_4, expect_row4);
//
// 	t_matrix expected = {
// 		{1,4,9,6},
// 		{2,3,8,7},
// 		{3,2,7,8},
// 		{4,1,6,9}
// 	};
// 	cr_expect_eq(TRUE, matrices_eq(result, expected));
// };
