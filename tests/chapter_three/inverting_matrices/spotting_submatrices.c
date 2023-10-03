/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotting_submatrices.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:56:41 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/03 17:08:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h""

// Scenario : A submatrix of a 3x3 matrix is a 2x2 matrix

#define scenario1 CYAN \
"\nGiven the following 3x3 matrix A:\n"                \
" | 1 | 5 | 0 |\n"               \
" | -3 | 2 | 7 |\n"               \
" | 0 | 6 | -3 |\n"                \
" Then submatrix(A, 0, 2) is the following 2x2 matrix:\n"                \
" | -3 | 2 |\n"               \
" | 0 | 6 |                "

// Scenario : A submatrix of a 4x4 matrix is a 3x3 matrix
#define scenario2 CYAN \
"\nGiven the following 4x4 matrix A:\n"                               \
" | -6 | 1 | 1 | 6 |\n"                               \
" | -8 | 5 | 8 | 6 |\n"                               \
" | -1 | 0 | 8 | 2 |\n"                               \
" | -7 | 1 | -1 | 1 |\n"                               \
" Then submatrix(A, 2, 1) is the following 3x3 matrix:\n"                               \
" | -6 | 1 | 6 |\n"                               \
" | -8 | 8 | 6 |\n"                               \
" | -7 | -1 | 1 |\n"                               \

Test(spotting_submatrices, submatrix_of_3x3_matrix, .description = scenario1) {
	t_3x3_matrix a = {
		{1,5,0},
		{-3,2,7},
		{0,6,-3}
	};
	t_2x2_matrix expected = {
		{-3,2},
		{0,6}
	};
	t_2x2_matrix result;

	result = submatrix_of_3x3_matrix(a, 0, 2);
	cr_expect_eq(TRUE, matrices_eq(result, expected));
}

Test(spotting_submatrices, submatrix_of_4x4_matrix, .description = scenario2) {
	t_matrix a = {
		{-6,1,1,6},
		{-8,5,8,6},
		{-1,0,8,2},
		{-7,1,-1,1}
	};
	t_3x3_matrix expected = {
		{-6,1,6},
		{-8,8,6},
		{-7,-1,1}
	};
	t_matrix result;

	result = submatrix_of_4x4_matrix(a, 2, 1);
	cr_expect_eq(TRUE, matrices_eq(result, expected));
}
