/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaining_transformations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:57:12 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/11 20:00:40 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Scenario : Individual transformations are applied in sequence
#include "minirt.h"
#include "tester.h"
#include <criterion/internal/test.h>
#include <math.h>

#define scenario1 CYAN \
"\nGiven p ← point(1, 0, 1)\n" \
"And A ← rotation_x(π / 2)\n" \
"And B ← scaling(5, 5, 5)\n" \
"And C ← translation(10, 5, 7)\n" \
"# apply rotation first\n"        \
"When p2 ← A * p\n"        \
"Then p2 = point(1, -1, 0)\n"        \
"# then apply scaling\n"        \
"When p3 ← B * p2\n"        \
"Then p3 = point(5, -5, 0)\n"        \
"# then apply translation\n"        \
"When p4 ← C * p3\n"        \
"Then p4 = point(15, 0, 7)\n"

Test(chaining_transformations, join, .description = scenario1)
{
	const t_tuple	p = {1,0,1, POINT};
	const t_matrix	_A = create_x_rotation_matrix(M_PI / 2);
	const t_matrix	_B = create_scaling_matrix(5, 5, 5);
	const t_matrix	_C = create_translation_matrix((t_tuple) {10, 5, 7});

//  rotation

	t_tuple p2_result;
	t_tuple expected_point = {1, -1, 0, POINT};
	multiply_tuple_by_matrix(p, _A, p2_result);
	cr_expect_tuples_eq(p2_result, expected_point);

// scaling

	t_tuple p3_result;
	t_tuple expected_point3 = {5, -5, 0, POINT};
	multiply_tuple_by_matrix(p2_result, _B, p3_result);
	cr_expect_tuples_eq(p3_result, expected_point3);
	
// transformation

	t_tuple p4_result;
	t_tuple expected_point4 = {15, 0, 7, POINT};
	multiply_tuple_by_matrix(p3_result, _C, p4_result);
	cr_expect_tuples_eq(p4_result, expected_point4);
}

// Scenario : Chained transformations must be applied in reverse order
#define scene2 CYAN \
"\nGiven p ← point(1, 0, 1)\n"  \
"And A ← rotation_x(π / 2)\n"  \
"And B ← scaling(5, 5, 5)\n"  \
"And C ← translation(10, 5, 7)\n"  \
"When T ← C * B * A\n"  \
"Then T * p = point(15, 0, 7)\n"

Test(chaining_transformations, reverse_order, .description = scene2)
{
	t_tuple 		result;
	const t_tuple	p = {1, 0, 1, POINT};
	const t_matrix	A = create_x_rotation_matrix(M_PI / 2);
	const t_matrix	B_ = create_scaling_matrix(5, 5, 5);
	const t_matrix	C = create_translation_matrix((t_tuple){10, 5, 7});
	const t_matrix	T = chain_transformations((t_matrix*[]){&A, &B_, &C, NULL});
	const t_tuple	expected = {15, 0, 7, POINT};

	print_4x4matrix(T);
	multiply_tuple_by_matrix(p, T, result);
	print_tuple(result);
	cr_expect_tuples_eq(result, expected);
}
