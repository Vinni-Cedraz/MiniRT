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

t_matrix	create_matrix_of_cofactors(const t_matrix m);
t_matrix	divide_transposed_matrix_by_determinant_of_the_original(t_matrix m);

t_matrix	invert_matrix(t_matrix m)
{
	t_matrix	cofact_mat;
	t_matrix	transposed_cofact_mat;
	t_matrix	res;

	cofact_mat = create_matrix_of_cofactors(m);
	transposed_cofact_mat = transpose_matrix(cofact_mat);
	res = divide_transposed_matrix_by_determinant_of_the_original(m);
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

t_matrix	divide_transposed_matrix_by_determinant_of_the_original(t_matrix m)
{
	int			i;
	t_matrix	res;
	const float	determinant = _4x4determinant(m);

	i = 0;
	while (++i < 4)
	{
		res.row_1[i] = m.row_1[i] / determinant;
		res.row_2[i] = m.row_2[i] / determinant;
		res.row_3[i] = m.row_3[i] / determinant;
		res.row_4[i] = m.row_4[i] / determinant;
	}
	return (res);
}

// #include "../../tests/tester.h"
// // check the cofactor matrix is correct
// Test(invert, cofactor_matrix) {
// 	const t_matrix m = {
// 		{5, 2, 6, -8},
// 		{1, -5, 1, 8},
// 		{7, 7, -6, -7},
// 		{1, -3, 7, 4},
// 	};
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
// 	print_tuple(res.row_1);
// 	print_tuple(res.row_2);
// 	print_tuple(res.row_3);
// 	print_tuple(res.row_4);
// }
