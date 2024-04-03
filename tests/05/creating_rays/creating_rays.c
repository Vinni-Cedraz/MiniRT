/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:47:50 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/13 19:09:43 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../tester.h"
#include <criterion/internal/test.h>

// Scenario: Creating and querying a ray
# define scenario1 CYAN \
"\nGiven origin ← point(1, 2, 3)\n" \
"And direction ← vector(4, 5, 6)\n" \
"When r ← create_ray(origin, direction)\n" \
"Then r.origin = origin\n"          \
"And r.direction = direction" RESET

Test(creating_rays, create_and_query_a_ray, .description = scenario1)
{
	t_tuple 	origin = {1, 2, 3, POINT};
	t_tuple		direction = {4, 5, 6, VECTOR};
	const t_ray	r = create_ray(origin, direction);

	cr_expect_tuples_eq(r.origin, origin);
	cr_expect_tuples_eq(r.direction , direction);
}

// Scenario: Computing a point from a distance
# define scenario2 CYAN \
"Given r ← ray(point(2, 3, 4), vector(1, 0, 0))\n"          \
"Then position(r, 0) = point(2, 3, 4)\n"          \
"And position(r, 1) = point(3, 3, 4)\n"          \
"And position(r, -1) = point(1, 3, 4)\n"          \
"And position(r, 2.5) = point(4.5, 3, 4)" RESET

Test(creating_rays, point_from_distance, .description = scenario2)
{
	const t_ray ray = create_ray(
			(t_tuple){2,3,4, POINT},
			(t_tuple){1,0,0, VECTOR}
	);
	t_tuple	result;

	result = get_position(ray, 0);
	cr_expect_tuples_eq(result, (t_tuple){2, 3, 4, POINT});
	result = get_position(ray, 1);
	cr_expect_tuples_eq(result, (t_tuple){3, 3, 4, POINT});
	result = get_position(ray, -1);
	cr_expect_tuples_eq(result, (t_tuple){1, 3, 4, POINT});
	result = get_position(ray, 2.5);
	cr_expect_tuples_eq(result, (t_tuple){4.5, 3, 4, POINT});
}
