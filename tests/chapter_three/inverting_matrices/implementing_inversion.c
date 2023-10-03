/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementing_inversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:13:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/03 18:32:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tester.h"
#include <criterion/internal/assert.h>

// Scenario : Testing an invertible matrix for invertibility
#define scenario1 CYAN \
"\nGiven the following 4x4 matrix A:\n"                               \
" | 6 | 4 | 4 | 4 |\n"                               \
" | 5 | 5 | 7 | 6 |\n"                               \
" | 4 | -9 | 3 | -7 |\n"                               \
" | 9 | 1 | 7 | -6 |\n"                               \
" Then determinant(A) = -2120\n"                               \
" And A is invertible"                               \

//Scenario : Testing a noninvertible matrix for invertibility
#define scenario2 CYAN \
"\nGiven the following 4x4 matrix A:\n"                               \
" | -4 | 2 | -2 | -3 |\n"                               \
" | 9 | 6 | 2 | 6 |\n"                               \
" | 0 | -5 | 1 | -5 |\n"                               \
" | 0 | 0 | 0 | 0 |\n"                               \
" Then determinant(A) = 0\n"                               \
" And A is not invertible\n"                               \

// Scenario : Calculating the inverse of a matrix
#define scenario3 CYAN \
"\nGiven the following 4x4 matrix A:\n"                               \
" | -5 | 2 | 6 | -8 |\n"                               \
" | 1 | -5 | 1 | 8 |\n"                               \
" | 7 | 7 | -6 | -7 |\n"                               \
" | 1 | -3 | 7 | 4 |\n"                               \
" And B ← inverse(A)\n"                               \
" Then determinant(A) = 532\n"                               \
" And cofactor(A, 2, 3) = -160\n"                               \
" And B[3,2] = -160/532\n"                               \
" And cofactor(A, 3, 2) = 105\n"                               \
" And B[2,3] = 105/532\n"                               \
" And B is the following 4x4 matrix:\n"                               \
" | 0.21805 | 0.45113 | 0.24060 | -0.04511 |\n"                               \
" | -0.80827 | -1.45677 | -0.44361 | 0.52068 |\n"                               \
" | -0.07895 | -0.22368 | -0.05263 | 0.19737 |\n"                               \
" | -0.52256 | -0.81391 | -0.30075 | 0.30639 |"                               \

Test(inversion, testing_an_invertible_matrix_for_invertibility, .description = scenario1) {
	t_matrix a = {
		{6,4,4,4},
		{5,5,7,6},
		{4,-9,3,-7},
		{9,1,7,-6}
	};

	cr_expect_eq(-2120, determinant(a));
	cr_expect_eq(TRUE, is_invertible(a));
}

Test(inversion, testing_a_noninvertible_matrix_for_invertibility, .description = scenario2) {
	t_matrix a = {
		{-4,2,-2,-3},
		{9,6,2,6},
		{0,-5,1,-5},
		{0,0,0,0}
	};

	cr_expect_eq(0, determinant(a));
	cr_expect_eq(FALSE, is_invertible(a));
}

Test(inversion, calculating_the_inverse_of_a_matrix, .description = scenario3) {
	t_matrix a = {
		{-5,2,6,-8},
		{1,-5,1,8},
		{7,7,-6,-7},
		{1,-3,7,4}
	};
	t_matrix b = inverse(a);
	cr_assert_eq(532, determinant(a));
	cr_assert_eq(-160, cofactor(a, 2, 3));
	cr_assert_eq(-160.0/532, b[3][2]);
	cr_assert_eq(105, cofactor(a, 3, 2));
	cr_assert_eq(TRUE, floats_eq(b.row_2[Z], 105.0/532));
	t_matrix expected = {
		{0.21805, 0.45113, 0.24060, -0.04511},
		{-0.80827, -1.45677, -0.44361, 0.52068},                               
		{-0.-0.07895, -0.22368, -0.05263, 0.19737},                              
		{-0.-0.52256, -0.81391, -0.30075, 0.30639},                               
	};

	cr_expect_eq(TRUE, matrices_eq(b, expected));
}
