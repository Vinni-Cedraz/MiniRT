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

#include "../../tester.h"
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdio.h>

// Scenario : An ft_lstnew encapsulates t and shape
#define scenario1 CYAN \
"\nGiven s ← sphere() \n"           \
"When i ← ft_lstnew(3.5, s)\n"           \
"Then i.t = 3.5\n"           \
"And i.shape = s\n"RESET

// Scenario : Aggregating intersections
#define scenario2 CYAN \
"\nGiven s ← sphere()\n"           \
"And i1 ← ft_lstnew(1, s)\n"           \
"And i2 ← ft_lstnew(2, s)\n"           \
"When xs ← intersections(i1, i2)\n"           \
"Then xs.count = 2\n"           \
"And xs[0].t = 1\n"           \
"And xs[1].t = 2\n"RESET

// Scenario : Intersect sets the shape on the ft_lstnew
#define scenario3 CYAN \
"\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"           \
"And s ← sphere()\n"           \
"When xs ← intersect(s, r)\n"           \
"Then xs.count = 2\n"           \
"And xs[0].shape = s\n"           \
"And xs[1].shape = s\n"RESET

Test(ft_lstnew, encapsulates_t_and_object, .description = scenario1)
{
	t_shape s = create_sphere();
	const t_node *node = ft_lstnew(3.5, &s);

	cr_expect_eq(doubles_eq(node->t, 3.5), true);
	cr_expect_eq(node->shape->type, SPHERE);
}

Test(ft_lstnew, sets_the_object, .description = scenario3)
{
	t_shape s = create_sphere();
	const t_ray r = create_ray((t_tuple){0,0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_intersections xs = intersect_sphere(&s, &r);

	cr_expect_eq(xs.count, 2);
	const t_shape *s1 = (t_shape*)xs.head->shape;
	const t_shape *s2 = (t_shape*)xs.head->next->shape;
	cr_expect_eq(s1->type, SPHERE);
	cr_expect_eq(s2->type, SPHERE);
}
