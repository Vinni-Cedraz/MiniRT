/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:45:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/08 10:45:24 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

// Scenario : Multiplying by a translation matrix
#define scenario1 CYAN "\nGiven translation_matrix ← translation(5, -3, 2)\n" \
						"And p ← point(-3, 4, 5)\n"						 \
						"Then translation_matrix * p = point(2, 1, 7)" RESET

// Scenario : Multiplying by the inverse of a translation matrix
#define scenario2 CYAN "\nGiven translation_matrix ← translation(5, -3, 2)\n" \
						"And inv ← inverse(translation_matrix)\n"             \
						"And p ← point(-3, 4, 5)\n"	                 \
						"Then inv * p = point(-8, 7, 3)" RESET

// Scenario : Translation does not affect vectors
#define scenario3 CYAN "\nGiven translation_matrix ← translation(5, -3, 2)"   \
						"And v ← vector(-3, 4, 5)\n"									     \
						"Then translation_matrix * v = v" RESET

Test(translation, multiplying_by_translation_matrix, .description = scenario1) {
	const t_tuple		p = {-3, 4, 5, POINT};
	const t_tuple		expected = {2, 1, 7, POINT};
	const t_matrix		translation_matrix = translation((t_tuple){5, -3, 2, POINT});
	t_tuple				result;

	multiply_tuple_by_matrix(p, translation_matrix, result);
	cr_expect_tuple_eq(result, expected);
}

Test(translation, multiplying_by_inverse_of_translation, .description = scenario2) {
	t_tuple			p;
	t_matrix		translation_matrix;
	t_matrix		inverse_of_translation_matrix;
	t_tuple			result; 

	translation_matrix = translation((t_tuple){5, -3, 2, POINT});
	inverse_of_translation_matrix = invert_matrix(translation_matrix);
 	p[X] = -3, p[Y] = 4, p[Z] = 5, p[W] = POINT;
	multiply_tuple_by_matrix(p, inverse_of_translation_matrix, result);
	const t_tuple	expected = {-8, 7, 3, POINT};
	cr_expect_tuple_eq(result, expected);
}

Test(translation, translation_shouldnt_affect_vectors, .description = scenario3) {
	const t_tuple	v = {-3, 4, 5, VECTOR};
	const t_tuple	expected = {-3, 4, 5, VECTOR};
	const t_matrix	translation_matrix = translation((t_tuple){5, -3, 2, POINT});
	t_tuple			result;

	multiply_tuple_by_matrix(v, translation_matrix, result);
	cr_expect_tuple_eq(result, expected);
}
