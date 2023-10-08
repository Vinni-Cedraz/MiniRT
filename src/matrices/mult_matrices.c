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

t_matrix	mult_matrices(t_matrix a, t_matrix b)
{
	t_matrix		result;
	const t_matrix	mat = transpose_matrix(b);

	multiply_tuple_by_matrix(a.row_1, mat, result.row_1);
	multiply_tuple_by_matrix(a.row_2, mat, result.row_2);
	multiply_tuple_by_matrix(a.row_3, mat, result.row_3);
	multiply_tuple_by_matrix(a.row_4, mat, result.row_4);
	return (result);
}

void	multiply_tuple_by_matrix(t_tuple row, t_matrix m, t_tuple res)
{
	res[X] = dot(row, m.row_1);
	res[Y] = dot(row, m.row_2);
	res[Z] = dot(row, m.row_3);
	res[W] = dot(row, m.row_4);
}

// #include "../../tests/tester.h"
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
