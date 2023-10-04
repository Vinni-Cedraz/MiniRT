/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulating_minors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:01:21 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/03 17:08:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"


// Scenario : Calculating a minor of a 3x3 matrix
#define scenario1 CYAN \
"\nGiven the following 3x3 matrix A:\n"                               \
" | 3 | 5 | 0 |\n"                               \
" | 2 | -1 | -7 |\n"                               \
" | 6 | -1 | 5 |\n"                               \
" And B ← submatrix(A, 1, 0)\n"                               \
" Then determinant(B) = 25\n"                               \
" And minor(A, 1, 0) = 25\n"                               \

Test(manipulating_minors, calculating_a_minor_of_a_3x3_matrix, .description = scenario1) {
	t_3x3matrix a = {
		{3,5,0},
		{2,-1,-7},
		{6,-1,5}
	};
	t_2x2matrix b = _3x3submatrix(a, 1, 0);

	cr_expect_eq(25, _2x2determinant(b));
	cr_expect_eq(25, _3x3minor(a, 1, 0));
}
