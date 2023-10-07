/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:41:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/05 16:07:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_matrix	create_matrix_of_cofactors(const t_matrix m);
t_matrix	divide_transposed_matrix_by_determinant(t_matrix m, float det);

t_bool	is_invertible(t_matrix m)
{
	if (_4x4determinant(m))
		return (TRUE);
	return (FALSE);
}

t_matrix	invert_matrix(t_matrix m)
{
	t_matrix		cofact_mat;
	t_matrix		transposed_cofact_mat;
	t_matrix		res;
	const float		det = _4x4determinant(m);

	cofact_mat = create_matrix_of_cofactors(m);
	transposed_cofact_mat = transpose_matrix(cofact_mat);
	res = divide_transposed_matrix_by_determinant(transposed_cofact_mat, det);
	return (res);
}

t_matrix	create_matrix_of_cofactors(const t_matrix m)
{
	int			i;
	t_matrix	res;

	i = -1;
	while (++i < 4)
	{
		res.row_1[i] = _4x4cofactor(m, ROW1, i);
		res.row_2[i] = _4x4cofactor(m, ROW2, i);
		res.row_3[i] = _4x4cofactor(m, ROW3, i);
		res.row_4[i] = _4x4cofactor(m, ROW4, i);
	}
	return (res);
}

t_matrix	divide_transposed_matrix_by_determinant(t_matrix m, const float det)
{
	int			i;
	t_matrix	res;

	i = -1;
	while (++i < 4)
	{
		res.row_1[i] = m.row_1[i] / det;
		res.row_2[i] = m.row_2[i] / det;
		res.row_3[i] = m.row_3[i] / det;
		res.row_4[i] = m.row_4[i] / det;
	}
	return (res);
}

// #include "../../tests/tester.h"
// // check the cofactor matrix is correct
// const t_matrix m = {
// 	{-5, 2, 6, -8},
// 	{1, -5, 1, 8},
// 	{7, 7, -6, -7},
// 	{1, -3, 7, 4},
// };
// Test(invert, cofactor_matrix) {
// 	const t_matrix expected = {
// 		.row_1 = {116, -430, -42, -278},
// 		.row_2 = {240, -775, -119, -433},
// 		.row_3 = {128, -236, -28, -160},
// 		.row_4 = {-24, 277, 105, 163},
// 	};
// 	const t_matrix res = create_matrix_of_cofactors(m);
// 	cr_expect_tuple_eq(res.row_1, expected.row_1);
// 	cr_expect_tuple_eq(res.row_2, expected.row_2);
// 	cr_expect_tuple_eq(res.row_3, expected.row_3);
// 	cr_expect_tuple_eq(res.row_4, expected.row_4);
// }
//
// Test(invert, transpose_of_cofactor) {
// 	const t_matrix expected = {
// 		.row_1 = {116,240, 128, -24},
// 		.row_2 = {-430, -775, -236, 277},
// 		.row_3 = {-42, -119, -28, 105},
// 		.row_4 = {-278, -433, -160, 163},
// 	};
// 	const t_matrix cofact = create_matrix_of_cofactors(m);
// 	const t_matrix res = transpose_matrix(cofact);
// 	cr_expect_tuple_eq(res.row_1, expected.row_1);
// 	cr_expect_tuple_eq(res.row_2, expected.row_2);
// 	cr_expect_tuple_eq(res.row_3, expected.row_3);
// 	cr_expect_tuple_eq(res.row_4, expected.row_4);
// }
//
// Test(invert, divide_transposed_matrix) {
// 	const t_matrix expected = {
// 		{0.21805, 0.45113, 0.24060, -0.04511},
// 		{-0.80827, -1.45677, -0.44361, 0.52068},                               
// 		{-0.07895, -0.22368, -0.05263, 0.19737},                              
// 		{-0.52256, -0.81391, -0.30075, 0.30639},                               
// 	};
// 	const float det = _4x4determinant(m);
// 	const t_matrix cofact = create_matrix_of_cofactors(m);
// 	const t_matrix trans = transpose_matrix(cofact);
// 	const t_matrix res = divide_transposed_matrix_by_determinant(trans , det);
// 	cr_expect_tuple_eq(res.row_1, expected.row_1);
// 	cr_expect_tuple_eq(res.row_2, expected.row_2);
// 	cr_expect_tuple_eq(res.row_3, expected.row_3);
// 	cr_expect_tuple_eq(res.row_4, expected.row_4);
// }
