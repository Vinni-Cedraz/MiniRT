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

// static void			turn_col_into_row(t_tuple col, t_tuple row);
// static void			init_col(t_matrix b, int col_idx, t_tuple col);

t_matrix	transpose_matrix(t_matrix m)
{
	const t_matrix	ma = {
			.grid = {
					{m.grid[0][0],m.grid[1][0] , m.grid[2][0], m.grid[3][0]},
					{m.grid[0][1], m.grid[1][1], m.grid[2][1], m.grid[3][1]},
					{m.grid[0][2], m.grid[1][2], m.grid[2][2], m.grid[3][2]},
					{m.grid[0][3], m.grid[1][3], m.grid[2][3], m.grid[3][3]},
			},
			.size = m.size
	};
	return (ma);
}

// static inline void	turn_col_into_row(t_tuple col, t_tuple row)
// {
// 	(void)col;
// 	(void)row;
// }
//
// static inline void	init_col(t_matrix b, int col_idx, t_tuple col)
// {
// 	(void)b;
// 	(void)col_idx;
// 	(void)col;
// }

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
