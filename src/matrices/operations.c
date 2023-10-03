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
#include <criterion/internal/test.h>

static void 


static void init_col(t_matrix b, int col_idx, t_tuple col)
{
	col[X] = b.row_1[col_idx];
	col[Y] = b.row_2[col_idx];
	col[Z] = b.row_3[col_idx];
	col[W] = b.row_4[col_idx];
}

t_matrix	mult_matrices(t_matrix a, t_matrix b)
{
	t_matrix		result;
	t_tuple			col;

	init_col(b, 0, col);
	result.row_1[X] = (float)dot(a.row_1, col);
	init_col(b, 1, col);
	result.row_1[Y] = (float)dot(a.row_1, col);
	init_col(b, 2, col);
	result.row_1[Z] = (float)dot(a.row_1, col);
	init_col(b, 3, col);
	result.row_1[W] = (float)dot(a.row_1, col);
}

#include "../../tests/tester.h"

Test(operations, init_col){
	t_matrix matrix = {
		.row_1 = {1, 2, 3, 4},
		.row_2 = {5, 6, 7, 8},
		.row_3 = {9, 10, 11, 12},
		.row_4 = {13, 14, 15, 16}
	};

	t_tuple expect_col = {1, 5, 9, 13};
	t_tuple col;

	init_col(matrix, 0, col);
	cr_expect_tuple_eq(col, expect_col);
}

Test(operations, mult_row_by_col){
	t_tuple row = {1, 2, 3, 4};
	t_tuple col = {5, 6, 7, 8};
	t_tuple expect = {70, 80, 90, 100};
	t_tuple result;

	cr_expect_tuple_eq(result, expect);
}

Test(operations, init_result_row){
	t_tuple row = {1, 2, 3, 4};
	t_tuple col = {5, 6, 7, 8};
	t_tuple expect = {70, 80, 90, 100};
	t_tuple result/* = {0, 0, 0, 0}*/;

	mult_row_by_col(row, col, result);
	cr_expect_tuple_eq(expected, result);
}
