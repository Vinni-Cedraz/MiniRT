/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking_intersections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:04:02 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/16 16:55:58 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../../tester.h"
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdio.h>

// Scenario : An intersection encapsulates t and object
#define scenario1 CYAN \
"\nGiven s ← sphere() \n"           \
"When i ← intersection(3.5, s)\n"           \
"Then i.t = 3.5\n"           \
"And i.object = s\n"RESET

// Scenario : Aggregating intersections
#define scenario2 CYAN \
"\nGiven s ← sphere()\n"           \
"And i1 ← intersection(1, s)\n"           \
"And i2 ← intersection(2, s)\n"           \
"When xs ← intersections(i1, i2)\n"           \
"Then xs.count = 2\n"           \
"And xs[0].t = 1\n"           \
"And xs[1].t = 2\n"RESET

// Scenario : Intersect sets the object on the intersection
#define scenario3 CYAN \
"\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"           \
"And s ← sphere()\n"           \
"When xs ← intersect(s, r)\n"           \
"Then xs.count = 2\n"           \
"And xs[0].object = s\n"           \
"And xs[1].object = s\n"RESET

Test(intersection, encapsulates_t_and_object, .description = scenario1)
{
	t_sphere s = create_sphere();
	const t_intersection xs = intersection(3.5, &s);

<<<<<<< HEAD
	cr_expect_eq(doubles_eq(n->t, 3.5), true);
	cr_expect_eq(((t_sphere *)(n->object))->type, SPHERE);
}

Test(intersection, aggregation_intersections, .description = scenario2)
{
	const t_sphere s = create_sphere();
	const t_sphere *s_ptr = &s;
	const t_node *i1 = intersection(1, (t_shape**)&s_ptr);
	const t_node *i2 = intersection(2, (t_shape**)&s_ptr);
	const t_node *arr[] = {i1, i2, NULL};
	const t_intersection xs = link_intersection_nodes(arr);

	cr_expect_eq(xs.count, 2);
	cr_expect_eq(doubles_eq(xs.head->t, 1), true);
	cr_expect_eq(doubles_eq(xs.head->next->t, 2), true);
}
=======
	cr_expect_eq(xs.t, 3.5);
	cr_expect_eq(s.type, SPHERE);
}

// Test(intersection, aggregation_intersections, .description = scenario2)
// {
// 	t_sphere s = create_sphere();
// 	const t_intersection i1 = intersection(1, &s);
// 	const t_intersection i2 = intersection(2, &s);
// 	const t_intersection *arr[] = {&i1, &i2, NULL};
// 	const t_intersection xs = link_intersection_nodes(arr);
//
// 	cr_expect_eq(xs.count, 2);
// 	cr_expect_eq(xs.head->t, 1);
// 	cr_expect_eq(xs.head->next->t, 2);
// }
>>>>>>> 53d2588080972a5156e0ad4440b83d083d973070

Test(intersection, sets_the_object, .description = scenario3)
{
	t_sphere s = create_sphere();
	const t_ray r = create_ray((t_tuple){0,0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_intersections xs = intersect(&s, r);

	cr_expect_eq(xs.count, 2);
	const t_sphere *s1 = (t_sphere*)xs.arr[0].object;
	const t_sphere *s2 = (t_sphere*)xs.arr[1].object;
	cr_expect_eq(s1->type, SPHERE);
	cr_expect_eq(s2->type, SPHERE);
}
