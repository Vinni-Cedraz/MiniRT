/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementing_inversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:13:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/05 16:07:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../tester.h"
#include <criterion/internal/assert.h>

// Scenario : Testing an invertible matrix for invertibility
#define scenario1 CYAN \
"\nGiven the following 4x4 matrix A:\n"                               \
" | 6 | 4 | 4 | 4 |\n"                               \
" | 5 | 5 | 7 | 6 |\n"                               \
" | 4 | -9 | 3 | -7 |\n"                               \
" | 9 | 1 | 7 | -6 |\n"                               \
" Then _4x4determinant(A) = -2120\n"                               \
" And A is invertible"                               \

//Scenario : Testing a noninvertible matrix for invertibility
#define scenario2 CYAN \
"\nGiven the following 4x4 matrix A:\n"                               \
" | -4 | 2 | -2 | -3 |\n"                               \
" | 9 | 6 | 2 | 6 |\n"                               \
" | 0 | -5 | 1 | -5 |\n"                               \
" | 0 | 0 | 0 | 0 |\n"                               \
" Then _4x4determinant(A) = 0\n"                               \
" And A is not invertible\n"                               \

Test(inversion, testing_an_invertible_matrix_for_invertibility, .description = scenario1) {
	t_matrix a = {
		.grid = {
			{6,4,4,4},
			{5,5,7,6},
			{4,-9,3,-7},
			{9,1,7,-6}
		},
		.size = 4
	};

	cr_expect_eq(-2120, _4x4determinant(a));
	cr_expect_eq(TRUE, is_invertible(a));
}

Test(inversion, testing_a_noninvertible_matrix_for_invertibility, .description = scenario2) {
	t_matrix a = {
		.grid = {
			{-4,2,-2,-3},
			{9,6,2,6},
			{0,-5,1,-5},
			{0,0,0,0}
		},
		.size = 4
	};

	cr_expect_eq(0, _4x4determinant(a));
	cr_expect_eq(FALSE, is_invertible(a));
}

// Scenario : Calculating the invert_matrix of a matrix
#define scenario3 CYAN \
"\nGiven the following 4x4 matrix A:\n"                               \
" | -5 | 2 | 6 | -8 |\n"                               \
" | 1 | -5 | 1 | 8 |\n"                               \
" | 7 | 7 | -6 | -7 |\n"                               \
" | 1 | -3 | 7 | 4 |\n"                               \
" And B ← invert_matrix(A)\n"                               \
" Then _4x4determinant(A) = 532\n"                               \
" And cofactor(A, 2, 3) = -160\n"                               \
" And B[3,2] = -160/532\n"                               \
" And cofactor(A, 3, 2) = 105\n"                               \
" And B[2,3] = 105/532\n"                               \
" And B is the following 4x4 matrix:\n"                               \
" | 0.21805 | 0.45113 | 0.24060 | -0.04511 |\n"                               \
" | -0.80827 | -1.45677 | -0.44361 | 0.52068 |\n"                               \
" | -0.07895 | -0.22368 | -0.05263 | 0.19737 |\n"                               \
" | -0.52256 | -0.81391 | -0.30075 | 0.30639 |"                               \


Test(inversion, calculating_the_inverse_of_a_matrix, .description = scenario3) {
	t_matrix a = {
		.grid = {
			{-5,2,6,-8},
			{1,-5,1,8},
			{7,7,-6,-7},
			{1,-3,7,4}
		},
		.size = 4
	};
	t_matrix b = invert_matrix(a);
	cr_assert_eq(532, _4x4determinant(a));
	cr_assert_eq(-160, _4x4cofactor(a, 2, 3));
	cr_assert_eq(TRUE, doubles_eq(-160.0/532, b.grid[3][2]));
	cr_assert_eq(105, _4x4cofactor(a, 3, 2));
	cr_assert_eq(TRUE, doubles_eq(b.grid[2][3], 105.0/532));
	t_matrix expected = {.grid = {
		{0.21805, 0.45113, 0.24060, -0.04511},
		{-0.80827, -1.45677, -0.44361, 0.52068},                               
		{-0.07895, -0.22368, -0.05263, 0.19737},                              
		{-0.52256, -0.81391, -0.30075, 0.30639},                               
	},
			 .size = 4
	};

	cr_expect_eq(TRUE, matrices_eq(b, expected));
}

// Scenario : Calculating the invert_matrix of another matrix
#define scenario4 CYAN "\nGiven the following 4x4 matrix A:\n" \
"| 8 | -5 | 9 | 2 |\n" \
"| 7 | 5 | 6 | 1 |\n" \
"| -6 | 0 | 9 | 6 |\n" \
"| -3 | 0 | -9 | -4 |\n" \
"Then invert_matrix(A) is the following 4x4 matrix:\n" \
"| -0.15385 | -0.15385 | -0.28205 | -0.53846 |\n" \
"| -0.07692 | 0.12308 | 0.02564 | 0.03077 |\n" \
"| 0.35897 | 0.35897 | 0.43590 | 0.92308 |\n" \
"| -0.69231 | -0.69231 | -0.76923 | -1.92308 |"

Test(inversion, calculating_the_inverse_of_another_matrix, .description = scenario4) {
	t_matrix a = {
		.grid = {
			{8,-5,9,2},
			{7,5,6,1},
			{-6,0,9,6},
			{-3,0,-9,-4}
		},
		.size = 4
	};
	t_matrix expected = {
		.grid = {
			{-0.15385, -0.15385, -0.28205, -0.53846},
			{-0.07692, 0.12308, 0.02564, 0.03077},
			{0.35897, 0.35897, 0.43590, 0.92308},
			{-0.69231, -0.69231, -0.76923, -1.92308}
		},
		.size = 4
	};

	cr_assert_eq(TRUE, matrices_eq(invert_matrix(a), expected));
}
// Scenario : Calculating the invert_matrix of a third matrix
#define scenario5 CYAN "\nGiven the following 4x4 matrix A:\n" \
"| 9 | 3 | 0 | 9 |\n" \
"| -5 | -2 | -6 | -3 |\n" \
"| -4 | 9 | 6 | 4 |\n" \
"| -7 | 6 | 6 | 2 |\n" \
"Then invert_matrix(A) is the following 4x4 matrix:\n" \
"| -0.04074 | -0.07778 | 0.14444 | -0.22222 |\n" \
"| -0.07778 | 0.03333 | 0.36667 | -0.33333 |\n" \
"| -0.02901 | -0.14630 | -0.10926 | 0.12963 |\n" \
"| 0.17778 | 0.06667 | -0.26667 | 0.33333 |" \

Test(inversion, calculating_the_inverse_of_a_third_matrix, .description = scenario5) {
	t_matrix a = {
		.grid = {
			{9,3,0,9},
			{-5,-2,-6,-3},
			{-4,9,6,4},
			{-7,6,6,2}
		},
		.size = 4
	};
	t_matrix expected = {
		.grid = {
			{-0.04074, -0.07778, 0.14444, -0.22222},
			{-0.07778, 0.03333, 0.36667, -0.33333},
			{-0.02901, -0.14630, -0.10926, 0.12963},
			{0.17778, 0.06667, -0.26667, 0.33333}
		},
		.size = 4
	};

	cr_assert_eq(TRUE, matrices_eq(invert_matrix(a), expected));
}

// Scenario : Multiplying a product by its invert_matrix
#define scenario6 CYAN "\nGiven the following 4x4 matrix A:\n"  \
"| 3 | -9 | 7 | 3 |\n" \
"| 3 | -8 | 2 | -9 |\n" \
"| -4 | 4 | 4 | 1 |\n" \
"| -6 | 5 | -1 | 1 |\n" \
"And the following 4x4 matrix B:\n" \
"| 8 | 2 | 2 | 2 |\n" \
"| 3 | -1 | 7 | 0 |\n" \
"| 7 | 0 | 5 | 4 |\n" \
"| 6 | -2 | 0 | 5 |\n" \
"And C ← A * B\n" \
"Then C * invert_matrix(B) = A" \

Test(inversion, multiplying_a_product_by_its_inverse, .description = scenario6) {
	t_matrix a = {
		.grid = {
			{3,-9,7,3},
			{3,-8,2,-9},
			{-4,4,4,1},
			{-6,5,-1,1}
		},
		.size = 4
	};
	t_matrix b = {
		.grid = {
			{8,2,2,2},
			{3,-1,7,0},
			{7,0,5,4},
			{6,-2,0,5}
		},
		.size = 4
	};
	t_matrix c = mult_matrices(a, b);
	cr_assert_eq(TRUE, matrices_eq(a, mult_matrices(c, invert_matrix(b))));
}
 
#define Scenario7 CYAN \
"\nGiven the following identity matrix A:"                      \
"\n"  \
"| 1 | 0 | 0 | 0 |\n"                      \
"| 0 | 1 | 0 | 0 |\n"                      \
"| 0 | 0 | 1 | 0 |\n"                      \
"| 0 | 0 | 0 | 1 |\n"                      \
"Then inverted(A) is the following matrix:\n"                      \
"| 1 | 0 | 0 | 0 |\n"                      \
"| 0 | 1 | 0 | 0 |\n"                      \
"| 0 | 0 | 1 | 0 |\n"                      \
"| 0 | 0 | 0 | 1 |"                      RESET

Test(inversion, identity_matrix_inversion, .description = Scenario7) {
	t_matrix a = {
		.grid = {
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,0,0,1}
		},
	 	.size = 4
	};
	t_matrix b = invert_matrix(a);
	cr_assert_eq(TRUE, matrices_eq(a, b));
}

// THIS TEST CRASHES IF I PRINT THE CONTENT OF THE ROWS!!!
// Scenario : inverting the inverse matrix
#define Scenario8 CYAN \
	"\nGiven matrix A\n" \
	"And matrix B = invert(A)\n" \
	"Then A == invert(B)"RESET

Test(inversion, inverse_by_the_inverse, .description = Scenario8) {
	t_matrix a = {
		.grid = {
			{3,-9,7,3},
			{3,-8,2,-9},
			{-4,4,4,1},
			{-6,5,-1,1}
		},
		.size = 4
	};
	t_matrix b = invert_matrix(a);
	// print_tuple(b.row_1);
	// print_tuple(b.rows[ROW1]);
	t_matrix c = invert_matrix(b);
	// print_tuple(c.row_1);
	// print_tuple(c.rows[ROW1]);
	cr_assert_eq(TRUE, matrices_eq(a, c));
}
