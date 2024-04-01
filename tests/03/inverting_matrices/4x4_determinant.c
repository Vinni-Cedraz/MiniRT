/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4x4_determinant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:09:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/04 17:53:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../tester.h"

// Scenario : Calculating the determinant of a 3x3 matrix
#define scenario1 CYAN \
"\nGiven the following 3x3 matrix A:\n"                               \
"| 1 | 2 | 6 |\n"                               \
"| -5 | 8 | -4 |\n"                               \
"| 2 | 6 | 4 |\n"                               \
"Then cofactor(A, 0, 0) = 56\n"                               \
"And cofactor(A, 0, 1) = 12\n"                               \
"And cofactor(A, 0, 2) = -46\n"                               \
"And determinant(A) = -196"                               \

// Scenario : Calculating the determinant of a 4x4 matrix
#define scenario2 CYAN \
"\nGiven the following 4x4 matrix A:\n"                               \
"| -2 | -8 | 3 | 5 |\n"                               \
"| -3 | 1 | 7 | 3 |\n"                               \
"| 1 | 2 | -9 | 6 |\n"                               \
"| -6 | 7 | 7 | -9 |\n"                               \
"Then cofactor(A, 0, 0) = 690\n"                               \
"And cofactor(A, 0, 1) = 447\n"                               \
"And cofactor(A, 0, 2) = 210\n"                               \
"And cofactor(A, 0, 3) = 51\n"                               \
"And determinant(A) = -4071"                               \


Test(determinant_large_matrices, calculating_the_determinant_of_a_3x3_matrix, .description = scenario1) {
	t_matrix a = {
		.grid  = {
			{1,2,6},
			{-5,8,-4},
			{2,6,4}
		},
		.size = 4
	};

	cr_expect_eq(56, _cofactor(a, 0, 0));
	cr_expect_eq(12 , _cofactor(a, 0, 1));
	cr_expect_eq(-46 , _cofactor(a, 0, 2));
	cr_expect_eq(doubles_eq(-196, _determinant(a)), TRUE);
}

Test(determinant_large_matrices, calculating_the_determinant_of_a_4x4_matrix, .description = scenario2) {
	t_matrix a = {
		.grid = {
			{-2,-8,3,5},
			{-3,1,7,3},
			{1,2,-9,6},
			{-6,7,7,-9}
		},
		.size = 4
	};

	cr_expect_eq(690, _cofactor(a, 0, 0));
	cr_expect_eq(447, _cofactor(a, 0, 1));
	cr_expect_eq(210, _cofactor(a, 0, 2));
	cr_expect_eq(51, _cofactor(a, 0, 3));
	cr_expect_eq(doubles_eq(-4071, _determinant(a)), TRUE);
}

Test(cofactor, a_1_1) {
	t_matrix a = {
		.grid = {
		{1,2,6},
		{-5,8,-4},
		{2,6,4}
		},
		.size = 4,
	};
	cr_expect_eq(56, _cofactor(a, 0, 0));
	cr_expect_eq(12 , _cofactor(a, 0, 1));
	cr_expect_eq(-46 , _cofactor(a, 0, 2));
	cr_expect_eq(28 , _cofactor(a, 1, 0));
	cr_expect_eq(-8 , _cofactor(a, 1, 1));
	cr_expect_eq(-2 , _cofactor(a, 1, 2));
	cr_expect_eq(-56 , _cofactor(a, 2, 0));
	cr_expect_eq(-26 , _cofactor(a, 2, 1));
	cr_expect_eq(18 , _cofactor(a, 2, 2));
}
