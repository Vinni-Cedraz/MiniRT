/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computing_cofactos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:07:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/03 17:08:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../tester.h"

// Scenario : Calculating a cofactor of a 3x3 matrix
#define scenario1 CYAN \
"\nGiven the following 3x3 matrix A:\n"           \
" | 3 | 5 | 0 |\n"                               \
" | 2 | -1 | -7 |\n"                             \
" | 6 | -1 | 5 |\n"                              \
" Then minor(A, 0, 0) = -12\n"                   \
" And cofactor(A, 0, 0) = -12\n"                 \
" And minor(A, 1, 0) = 25\n"                     \
" And cofactor(A, 1, 0) = -25"RESET              \

Test(computing_cofactor, calculating_a_cofactor_of_a_3x3_matrix, .description = scenario1) {
	t_matrix a = create_matrix((double []){
			3,5,0,
			2,-1,-7,
			6,-1,5,
			END_MATRIX
	});

	cr_expect_eq(-12, _minor(a, 0, 0));
	cr_expect_eq(-12, _cofac(a, 0, 0));
	cr_expect_eq(25, _minor(a, 1, 0));
	cr_expect_eq(-25, _cofac(a, 1, 0));
}
