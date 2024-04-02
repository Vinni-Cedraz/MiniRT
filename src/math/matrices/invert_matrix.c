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

static t_matrix	create_matrix_of_cofactors(const t_matrix m);
static t_matrix	divide_each_element_by_det(t_matrix m, \
		const double det);

t_bool	is_invertible(t_matrix m)
{
	if (m.size == 4 && _determinant(m))
		return (true);
	return (false);
}

t_matrix	invert_matrix(t_matrix m)
{
	t_matrix		inverted_matrix;
	const double	det = _determinant(m);

	inverted_matrix = create_identity_matrix();
	if (is_invertible(m))
	{
		inverted_matrix = transpose_matrix(create_matrix_of_cofactors(m));
		inverted_matrix = divide_each_element_by_det(inverted_matrix, det);
		return (inverted_matrix);
	}
	return (m);
}

static t_matrix	create_matrix_of_cofactors(const t_matrix m)
{
	return (create_matrix((double []){
			_cofac(m, 0, 0), _cofac(m, 0, 1), _cofac(m, 0, 2), _cofac(m, 0, 3),
			_cofac(m, 1, 0), _cofac(m, 1, 1), _cofac(m, 1, 2), _cofac(m, 1, 3),
			_cofac(m, 2, 0), _cofac(m, 2, 1), _cofac(m, 2, 2), _cofac(m, 2, 3),
			_cofac(m, 3, 0), _cofac(m, 3, 1), _cofac(m, 3, 2), _cofac(m, 3, 3),
			END_MATRIX
		}));
}

static double	_div(t_matrix m, double d)
{
	static int	i;
	static int	j;

	if (j == 3)
	{
		i++;
		j = 0;
	}
	if (i == 3)
		i = 0;
	return (m.grid[i][j] / d);
}

static t_matrix	divide_each_element_by_det(t_matrix m, const double d)
{
	return (create_matrix((double []){
			_div(m, d), _div(m, d), _div(m, d), _div(m, d),
			_div(m, d), _div(m, d), _div(m, d), _div(m, d),
			_div(m, d), _div(m, d), _div(m, d), _div(m, d),
			_div(m, d), _div(m, d), _div(m, d), _div(m, d),
			END_MATRIX
		}));
}

// #include "../../../tests/tester.h"
//
// Test(invert, cofactor_matrix) {
// 	const t_matrix m = create_matrix((double []){
// 		-5, 2, 6, -8,
// 		1, -5, 1, 8,
// 		7, 7, -6, -7,
// 		1, -3, 7, 4,
// 		END_MATRIX
// 	});
// 	const t_matrix expected = create_matrix((double []){
// 		116, -430, -42, -278,
// 		240, -775, -119, -433,
// 		128, -236, -28, -160,
// 		-24, 277, 105, 163,
// 		END_MATRIX
// 	});
// 	const t_matrix res = create_matrix_of_cofactors(m);
// 	matrices_eq(res, expected);
// }
//
// Test(invert, transpose_of_cofactor) {
// 	const t_matrix m = create_matrix((double []){
// 		1, -5, 1, 8,
// 		-5, 2, 6, -8,
// 		7, 7, -6, -7,
// 		1, -3, 7, 4,
// 		END_MATRIX
// 	});
// 	const t_matrix expected = create_matrix((double []){
// 		-430, -775, -236, 277,
// 		116, 240, 128, -24,
// 		-42, -119, -28, 105,
// 		-278, -433, -160, 163,
// 		END_MATRIX
// 	});
// 	const t_matrix cofact = create_matrix_of_cofactors(m);
// 	const t_matrix res = transpose_matrix(cofact);
// 	matrices_eq(res, expected);
// }
//
// Test(invert, divide_transposed_matrix) {
// 	const t_matrix m = create_matrix((double []){
// 		1, -5, 1, 8,
// 		-5, 2, 6, -8,
// 		7, 7, -6, -7,
// 		1, -3, 7, 4,
// 		END_MATRIX
// 	});
// 	const t_matrix expected = create_matrix((double []){
// 		-0.80827, -1.45677, -0.44361, 0.52068,
// 		0.21805, 0.45113, 0.24060, -0.04511,
// 		-0.07895, -0.22368, -0.05263, 0.19737,
// 		-0.52256, -0.81391, -0.30075, 0.30639,
// 		END_MATRIX
// 	});
// 	const double det = _determinant(m);
// 	const t_matrix cofact = create_matrix_of_cofactors(m);
// 	const t_matrix trans = transpose_matrix(cofact);
// 	const t_matrix res = divide_each_element_by_det(trans, det);
// 	matrices_eq(res, expected);
// }
//
// Test(invert, cofactor_matrix_of_identity_matrix) {
// 	const t_matrix m = create_matrix((double []) {
// 			1, 0, 0, 0,
// 			0, 1, 0, 0,
// 			0, 0, 1, 0,
// 			0, 0, 0, 1,
// 			END_MATRIX
// 	});
// 	const t_matrix expected = create_matrix((double []) {
// 			1, 0, 0, 0,
// 			0, 1, 0, 0,
// 			0, 0, 1, 0,
// 			0, 0, 0, 1,
// 			END_MATRIX
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
//  	p.x = -3, p.y = 4, p.z = 5, p.w = POINT;
// 	printf(CYAN"translation matrix: \n"RESET);
// 	print_matrix(translation_matrix);
// 	printf(CYAN"inverse matrix: \n"RESET);
// 	print_matrix(inverse_of_translation_matrix);
// 	result = multiply_tuple_by_matrix((double[]){p.x, p.y, p.z, p.w}, inverse_of_translation_matrix, p.w);
// 	printf(CYAN"result point: \n"RESET);
// 	print_tuple(result);
// 	printf(CYAN"expected point: \n"RESET);
// 	const t_tuple	expected = {-8, 7, 3, POINT};
// 	print_tuple(expected);
// 	cr_expect_tuples_eq(result, expected);
// }
//
// Test(invert, matrix_of_divisions_of_everything_by_original_det) {
// 	const t_matrix m = create_matrix((double []){
// 		0, 1, 0, 3,
// 		1, 0, 0, -5,
// 		0, 0, 1, -2,
// 		0, 0, 0, 1,
// 		END_MATRIX
// 	});
// 	const t_matrix expected = create_matrix((double []){
// 		0, 1, 0, 3,
// 		1, 0, 0, -5,
// 		0, 0, 1, -2,
// 		0, 0, 0, 1,
// 		END_MATRIX
// 	});
// 	const int det = _determinant(m);
// 	const t_matrix result = divide_each_element_by_det(m, det);
// 	cr_expect_eq(matrices_eq(result, expected), TRUE);
// }
