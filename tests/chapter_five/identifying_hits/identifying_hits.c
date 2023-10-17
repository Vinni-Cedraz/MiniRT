/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifying_hits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:47:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/17 16:22:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "minirt.h"
#include "tester.h"
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

// Scenario : The hit, when all intersections have positive t
#define scenario1 CYAN \
"Given s ← sphere()\n" \
"And i1 ← intersection(1, s)\n" \
"And i2 ← intersection(2, s)\n" \
"And xs ← intersections(i2, i1)\n" \
"When i ← hit(xs)\n" \
"Then i = i1\n" RESET

Test(identifying_hits, positive_t, .description = scenario1)
{
	const t_sphere s = create_sphere();
	const t_node *i1 = intersection(1, (void *)&s);
	const t_node *i2 = intersection(2, (void *)&s);
	const t_intersection xs = create_intersections(i1, i2);

	hit(xs);
	cr_expect_eq(&i1, xs.head);
}

// Scenario : The hit, when some intersections have negative t
#define scenario2 CYAN \
"Given s ← sphere()\n" \
"And i1 ← intersection(-1, s)\n" \
"And i2 ← intersection(1, s)\n" \
"And xs ← intersections(i2, i1)\n" \
"When i ← hit(xs)\n" \
"Then i = i2\n" RESET

Test(identifying_hits, negative_t, .description = scenario2)
{
	const t_sphere s = create_sphere();
	const t_node *i1 = intersection(-1, (void *)&s);
	const t_node *i2 = intersection(1, (void *)&s);
	const t_intersection xs = create_intersections(i1, i2);

	hit(xs);
	cr_expect_eq(&i1, xs.head);
}

// Scenario : The hit, when all intersections have negative t
#define scenario3 CYAN \
"Given s ← sphere()\n" \
"And i1 ← intersection(-2, s)\n" \
"And i2 ← intersection(-1, s)\n" \
"And xs ← intersections(i2, i1)\n" \
"When i ← hit(xs)\n" \
"Then i is nothing\n" RESET

Test(identifying_hits, all_negatives, .description = scenario3)
{
	const t_sphere s = create_sphere();
	const t_node *i1 = intersection(-2, (void *)&s);
	const t_node *i2 = intersection(-1, (void *)&s);
	const t_intersection xs = create_intersections(i1, i2);

	hit(xs);
	cr_expect_eq(&i1, NULL);
}
// Scenario : The hit is always the lowest nonnegative intersection
#define scenario4 CYAN \
"Given s ← sphere()\n" \
"And i1 ← intersection(5, s)\n" \
"And i2 ← intersection(7, s)\n" \
"And i3 ← intersection(-3, s)\n" \
"And i4 ← intersection(2, s)\n" \
"And xs ← intersections(i1, i2, i3, i4)\n" \
"When i ← hit(xs)\n" \
"Then i = i4\n" RESET

Test(identifying_hits, hit_is_alway_lowest_nonnegative intersection, .description = scenario3)
{
	const t_sphere s = create_sphere();
	const t_node *i1 = intersection(5, (void *)&s);
	const t_node *i2 = intersection(7, (void *)&s);
	const t_node *i3 = intersection(-3, (void *)&s);
	const t_node *i4 = intersection(2, (void *)&s);
	const t_intersection xs = create_intersections(i1, i2, i3, i4);

	hit(xs);
	cr_expect_eq(&i1, NULL);
}
