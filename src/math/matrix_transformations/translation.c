/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:07:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/08 11:13:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	create_translation_matrix(t_tuple point)
{
}

// #include "../../tests/tester.h"
// //
// Test(invert, cofactor_matrix_of_translation_matrix) {
// 	const t_matrix m = create_4x4_matrix(&(t_matrix) {
// 			{1, 0, 0, 5},
// 			{0, 1, 0, -3},
// 			{0, 0, 1, 2},
// 			{0, 0, 0, 1},
// 			{NULL},
// 	});
// 	const t_matrix expected = create_4x4_matrix(&(t_matrix) {
// 			{1, 0, 0, 0},
// 			{0, 1, 0, 0},
// 			{0, 0, 1, 0},
// 			{-5, 3, -2, 1},
// 			{NULL}
// 	});
// 	t_matrix res = create_matrix_of_cofactors(m);
// 	printf(CYAN"matrix of cofactors:\n"RESET);
// 	print_4x4matrix(res);
// 	cr_expect_eq(TRUE, matrices_eq(res, expected));
// }
//
// //
// Test(invert, transpose_of_cofactor_of_translation_matrix) {
// 	t_matrix cofact = create_4x4_matrix(&(t_matrix){
// 		  {1,0,0,0},
// 		  {0,1,0,0},
// 		  {0,0,1,0},
// 		{-5,3,-2,1},
// 		{NULL}
// 	});
// 	const t_matrix expected = create_4x4_matrix(&(t_matrix){
// 		.row_1 = {1, 0, 0, -5},
// 		.row_2 = {0, 1, 0, 3},
// 		.row_3 = {0, 0, 1, -2},
// 		.row_4 = {0, 0, 0, 1},
// 		{NULL}
// 	});
// 	const t_matrix res = transpose_matrix(cofact);
// 	printf(CYAN"transpose_of_cofact:\n"RESET);
// 	print_4x4matrix(res);
// 	cr_expect_tuple_eq(res.row_1, expected.row_1);
// 	cr_expect_tuple_eq(res.row_2, expected.row_2);
// 	cr_expect_tuple_eq(res.row_3, expected.row_3);
// 	cr_expect_tuple_eq(res.row_4, expected.row_4);
// }
// //
// // Test(invert, determinant_of_translation_matrix) {
// // 	const t_matrix m = create_4x4_matrix(&(t_matrix){
// // 	     	{1, 0, 0, 5},
// // 			{0, 1, 0, -3},
// // 			{0, 0, 1, 2},
// // 			{0, 0, 0, 1},
// // 			{NULL}
// // 	});
// // 	const int expected = 1;
// // 	const int res = _4x4determinant(m);
// // 	cr_expect_eq(expected, res);
// // }
