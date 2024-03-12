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

// #include "../../../tests/tester.h"

// t_matrix	create_matrix_of_cofactors(const t_matrix m);
// t_matrix	divide_transposed_matrix_by_determinant(t_matrix m, double det);

t_bool	is_invertible(t_matrix m)
{
	(void)m;
	return (TRUE);
}

t_matrix	invert_matrix(t_matrix m)
{
	(void)m;
	return (m);
}

// static t_matrix	create_matrix_of_cofactors(const t_matrix m)
// {
// }
//
// static t_matrix	divide_transposed_matrix_by_determinant(t_matrix m,
// 		const double det)
// {
// }

// // check the cofactor matrix is correct
// Test(invert, cofactor_matrix) {
// 	const t_matrix m = create_4x4_matrix(&(t_matrix){
// 		{-5, 2, 6, -8},
// 		{1, -5, 1, 8},
// 		{7, 7, -6, -7},
// 		{1, -3, 7, 4},
// 		{NULL}
// 	});
// 	const t_matrix expected = create_4x4_matrix(&(t_matrix){
// 		.row_1 = {116, -430, -42, -278},
// 		.row_2 = {240, -775, -119, -433},
// 		.row_3 = {128, -236, -28, -160},
// 		.row_4 = {-24, 277, 105, 163},
// 		{NULL}
// 	});
// 	const t_matrix res = create_matrix_of_cofactors(m);
// 	cr_expect_tuples_eq(res.row_1, expected.row_1);
// 	cr_expect_tuples_eq(res.row_2, expected.row_2);
// 	cr_expect_tuples_eq(res.row_3, expected.row_3);
// 	cr_expect_tuples_eq(res.row_4, expected.row_4);
// }
//
// Test(invert, transpose_of_cofactor) {
// 	const t_matrix m = create_4x4_matrix(&(t_matrix){
// 		{-5, 2, 6, -8},
// 		{1, -5, 1, 8},
// 		{7, 7, -6, -7},
// 		{1, -3, 7, 4},
// 		{NULL}
// 	});
// 	const t_matrix expected = create_4x4_matrix(&(t_matrix){
// 		.row_1 = {116, 240, 128, -24},
// 		.row_2 = {-430, -775, -236, 277},
// 		.row_3 = {-42, -119, -28, 105},
// 		.row_4 = {-278, -433, -160, 163},
// 		{NULL}
// 	});
// 	const t_matrix cofact = create_matrix_of_cofactors(m);
// 	const t_matrix res = transpose_matrix(cofact);
// 	cr_expect_tuples_eq(res.row_1, expected.row_1);
// 	cr_expect_tuples_eq(res.row_2, expected.row_2);
// 	cr_expect_tuples_eq(res.row_3, expected.row_3);
// 	cr_expect_tuples_eq(res.row_4, expected.row_4);
// }
//
// Test(invert, divide_transposed_matrix) {
// 	const t_matrix m = create_4x4_matrix(&(t_matrix){
// 		{-5, 2, 6, -8},
// 		{1, -5, 1, 8},
// 		{7, 7, -6, -7},
// 		{1, -3, 7, 4},
// 		{NULL}
// 	});
// 	const t_matrix expected = create_4x4_matrix(&(t_matrix){
// 		{0.21805, 0.45113, 0.24060, -0.04511},
// 		{-0.80827, -1.45677, -0.44361, 0.52068},
// 		{-0.07895, -0.22368, -0.05263, 0.19737},
// 		{-0.52256, -0.81391, -0.30075, 0.30639},
// 		{NULL}
// 	});
// 	const double det = _4x4determinant(m);
// 	const t_matrix cofact = create_matrix_of_cofactors(m);
// 	const t_matrix trans = transpose_matrix(cofact);
// 	const t_matrix res = divide_transposed_matrix_by_determinant(trans , det);
// 	cr_expect_tuples_eq(res.row_1, expected.row_1);
// 	cr_expect_tuples_eq(res.row_2, expected.row_2);
// 	cr_expect_tuples_eq(res.row_3, expected.row_3);
// 	cr_expect_tuples_eq(res.row_4, expected.row_4);
// }
//
// Test(invert, cofactor_matrix_of_identity_matrix) {
// 	const t_matrix m = create_4x4_matrix(&(t_matrix) {
// 			{1, 0, 0, 0},
// 			{0, 1, 0, 0},
// 			{0, 0, 1, 0},
// 			{0, 0, 0, 1},
// 			{NULL}
// 	});
// 	const t_matrix expected = create_4x4_matrix(&(t_matrix) {
// 			{1, 0, 0, 0},
// 			{0, 1, 0, 0},
// 			{0, 0, 1, 0},
// 			{0, 0, 0, 1},
// 			{NULL}
// 	});
// 	const t_matrix res = create_matrix_of_cofactors(m);
// 	cr_expect_eq(TRUE, matrices_eq(res, expected));
// }
//
// Test(translation, multiplying_by_inverse_of_translation) {
// 	t_tuple			p;
// 	t_matrix		translation_matrix;
// 	t_matrix		inverse_of_translation_matrix;
// 	t_tuple			result;
//
// 	translation_matrix = create_translation_matrix((t_tuple){5, -3, 2, POINT});
// 	inverse_of_translation_matrix = invert_matrix(translation_matrix);
//  	p[X] = -3, p[Y] = 4, p[Z] = 5, p[W] = POINT;
// 	printf(CYAN"translation matrix: \n"RESET);
// 	print_4x4matrix(translation_matrix);
// 	printf(CYAN"inverse matrix: \n"RESET);
// 	print_4x4matrix(inverse_of_translation_matrix);
// 	multiply_tuple_by_matrix(p, inverse_of_translation_matrix, result);
// 	printf(CYAN"result point: \n"RESET);
// 	print_tuple(result);
// 	printf(CYAN"expected point: \n"RESET);
// 	const t_tuple	expected = {-8, 7, 3, POINT};
// 	print_tuple(expected);
// 	cr_expect_tuples_eq(result, expected);
// }
//
// Test(invert, matrix_of_divisions_of_everything_by_original_det) {
// 	const t_matrix m = create_4x4_matrix(&(t_matrix){
// 		.row_1 = {1, 0, 0, -5},
// 		.row_2 = {0, 1, 0, 3},
// 		.row_3 = {0, 0, 1, -2},
// 		.row_4 = {0, 0, 0, 1},
// 		{NULL}
// 	});
// 	const t_matrix expected = create_4x4_matrix(&(t_matrix){
// 		.row_1 = {1, 0, 0, -5},
// 		.row_2 = {0, 1, 0, 3},
// 		.row_3 = {0, 0, 1, -2},
// 		.row_4 = {0, 0, 0, 1},
// 		{NULL}
// 	});
// 	const int det = _4x4determinant(m);
// 	const t_matrix result = divide_transposed_matrix_by_determinant(m, det);
// 	cr_expect_eq(matrices_eq(result, expected), TRUE);
// }
