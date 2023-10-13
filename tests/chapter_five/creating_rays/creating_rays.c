/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:47:50 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/13 18:26:37 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <criterion/internal/test.h>

// Scenario: Creating and querying a ray

# define scenario1 CYAN \
"\nGiven origin ← point(1, 2, 3)\n" \
"And direction ← vector(4, 5, 6)\n" \
"When r ← ray(origin, direction)\n" \
"Then r.origin = origin\n"          \
"And r.direction = direction\n"

Test(creating_rays, create_and_query_a_ray, .description = scenario1)
{
	t_tuple origin = {1, 2, 3, POINT};
	t_tuple direction = {4, 5, 6, VECTOR};
	const t_ray r = create_ray(origin, direction);

	print_tuple(r.origin);
	cr_expect_tuple_eq(r.origin, origin);
	cr_expect_tuple_eq(r.direction , direction);
}

// Scenario: Computing a point from a distance
# define scenario2 CYAN \
"Given r ← ray(point(2, 3, 4), vector(1, 0, 0))\n"          \
"Then position(r, 0) = point(2, 3, 4)\n"          \
"And position(r, 1) = point(3, 3, 4)\n"          \
"And position(r, -1) = point(1, 3, 4)\n"          \
"And position(r, 2.5) = point(4.5, 3, 4)\n"

Test(creating_rays, point_from_distance, .description = scenario2)
{
	const t_ray ray = create_ray(
			(t_tuple){2,3,4, POINT},
			(t_tuple){1,0,0, VECTOR}
			);


	const t_tuple pos1 = get_point_from_distance(r,0);
	const t_tuple pos2 = get_point_from_distance(r,0);
	const t_tuple pos3 = get_point_from_distance(r,0);
	const t_tuple pos4 = get_point_from_distance(r,0);

}

