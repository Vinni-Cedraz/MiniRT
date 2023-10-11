/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:09:58 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/11 16:35:28 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tester.h"

//Scenario : A scaling matrix applied to a point
#define scenario1 CYAN \
"\nGiven transform ← scaling(2, 3, 4)\n" \
"And p ← point(-4, 6, 8)\n" \
"Then transform * p = point(-8, 18, 32)\n" 

// Scenario : A scaling matrix applied to a vector
#define scenario2 CYAN \
"\nGiven transform ← scaling(2, 3, 4)\n" \
"And v ← vector(-4, 6, 8)\n" \
"Then transform * v = vector(-8, 18, 32)\n "

// Scenario : Multiplying by the inverse of a scaling matrix
# define scenario3 CYAN \ 
"\nGiven transform ← scaling(2, 3, 4)\n"\
"And inv ← inverse(transform)\n" \
"And v ← vector(-4, 6, 8)\n" \
"Then inv * v = vector(-2, 2, 2)\n" \

// Scenario : Reflection is scaling by a negative value
#define scenario4 CYAN \
"Given transform ← scaling(-1, 1, 1)\n" \
"And p ← point(2, 3, 4)\n" \
"Then transform * p = point(-2, 3, 4)\n"

Test(scaling, apply_scaling_matrix_to_a_point, .description=scenario1)
{
	t_matrix transform;
	const t_tuple	point = {-4,6,8, POINT};
	const t_tuple	result;
	const t_tuple	expected = {-8, 18, 32, POINT};

	transform = create_scaling_matrix(2, 3, 4);
	multiply_tuple_by_matrix(point, transform, result);
	cr_expect_tuple_eq(result, expected);
}

Test(scaling, apply_scaling_matrix_to_a_vector, .description=scenario2)
{
	t_matrix transform;
	const t_tuple	vector = {-4,6,8, VECTOR};
	const t_tuple	result;
	const t_tuple	expected = {-8, 18, 32, VECTOR};

	transform = create_scaling_matrix(2, 3, 4);
	multiply_tuple_by_matrix(vector, transform, result);
	cr_expect_tuple_eq(result, expected);
}

Test(scaling, multiply_by_inverse_scaling_matrix, .description=scenario3)
{
	t_matrix transform;
	t_matrix inv;
	const t_tuple	vector = {-4,6,8, VECTOR};
	const t_tuple	result;
	const t_tuple	expected = {-2, 2, 2, VECTOR};

	transform = create_scaling_matrix(2, 3, 4);
	inv = invert_matrix(transform);
	multiply_tuple_by_matrix(vector, inv, result);
	cr_expect_tuple_eq(result, expected);
}

Test(scaling, scaling_by_negative_value, .description=scenario4)
{
	t_matrix transform;
	t_matrix inv;
	const t_tuple	point = {2, 3, 4, POINT};
	const t_tuple	result;
	const t_tuple	expected = {-2, 3, 4, POINT};

	transform = create_scaling_matrix(-1, 1, 1);
	multiply_tuple_by_matrix(point, transform, result);
	cr_expect_tuple_eq(result, expected);
}
