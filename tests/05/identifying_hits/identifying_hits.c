#include "tester.h"
#include <stdio.h>

// Scenario : The hit, when all intersections have positive t
#define scenario1 CYAN \
"Given s ← sphere()\n" \
"And i1 ← intersection(1, s)\n" \
"And i2 ← intersection(2, s)\n" \
"And xs ← intersections(i2, i1)\n" \
"When hit ← get_hit(xs)\n" \
"Then hit = i1\n" RESET

Test(identifying_hits, positive_t, .description = scenario1) {
	const t_sphere s = create_sphere();
	const t_sphere *s_ptr = &s;
	const t_node *arr[] = {
		intersection(1, (t_shape **)&s_ptr),
		intersection(2, (t_shape **)&s_ptr),
		NULL
	};
	const t_intersection xs = link_intersection_nodes(arr);
	const t_node hit = get_hit(xs);
	cr_expect_eq(hit.t, 1);
}

// Scenario : The hit, when some intersections have negative t
#define scenario2 CYAN \
"Given s ← sphere()\n" \
"And i1 ← intersection(-1, s)\n" \
"And i2 ← intersection(1, s)\n" \
"And xs ← intersections(i2, i1)\n" \
"When hit ← get_hit(xs)\n" \
"Then hit = i2\n" RESET

Test(identifying_hits, negative_t, .description = scenario2)
{
	const t_sphere s = create_sphere();
	const t_sphere *s_ptr = &s;
	const t_node *arr[] = {
		intersection(-1, (t_shape **)&s_ptr),
		intersection(1, (t_shape **)&s_ptr),
		NULL
	};
	const t_intersection xs = link_intersection_nodes(arr);
	const t_node hit = get_hit(xs);
	printf("%f\n", hit.t);
	cr_expect_eq(hit.t, 1);
}

// Scenario : The hit, when all intersections have negative t
#define scenario3 CYAN \
"Given s ← sphere()\n" \
"And i1 ← intersection(-2, s)\n" \
"And i2 ← intersection(-1, s)\n" \
"And xs ← intersections(i2, i1)\n" \
"When hit ← get_hit(xs)\n" \
"Then hit is nothing\n" RESET

Test(identifying_hits, all_negatives, .description = scenario3)
{
	const t_sphere s = create_sphere();
	const t_sphere *s_ptr = &s;
	const t_node *arr[] = { 
		intersection(-2, (t_shape **)&s_ptr),
		intersection(-1, (t_shape **)&s_ptr),
		NULL
	};
	const t_intersection xs = link_intersection_nodes(arr);
	const t_node hit = get_hit(xs);
	cr_expect_eq(hit.object, NULL);
}

// Scenario : The hit is always the lowest nonnegative intersection
#define scenario4 CYAN \
"Given s ← sphere()\n" \
"And i1 ← intersection(5, s)\n" \
"And i2 ← intersection(7, s)\n" \
"And i3 ← intersection(-3, s)\n" \
"And i4 ← intersection(2, s)\n" \
"And xs ← intersections(i1, i2, i3, i4)\n" \
"When hit ← get_hit(xs)\n" \
"Then hit = i4\n" RESET

Test(identifying_hits, hit_is_alway_lowest_nonnegative_intersection, .description = scenario4)
{
	const t_sphere s = create_sphere();
	const t_sphere *s_ptr = &s;
	const t_node *arr[] = {
		intersection(5, (void *)&s_ptr),
		intersection(7, (void *)&s_ptr),
		intersection(-3, (void *)&s_ptr),
		intersection(2, (void *)&s_ptr),
		NULL
	};
	const t_intersection xs = link_intersection_nodes(arr);
	const t_node hit = get_hit(xs);
	cr_expect_eq(hit.t, 2);
}
