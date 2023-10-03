/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2x2_determinant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:53:15 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/03 16:56:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <criterion/internal/test.h>

// Scenario : Calculating the determinant of a 2x2 matrix

#define Scenario1 CYAN \
"\nGiven the following 2x2 matrix A:\n"         \
"| 1 | 5 |\n"                                    \
"| -3 | 2 |\n"                                    \
"Then determinant(A) = 17" RESET

Test(inverting_matrices, determinant_of_2x2_matrix, .description = Scenario1) {
	t_matrix a = {
		{1,5},
		{-3,2}
	};

	cr_expect_eq(17, determinant(a));
}
