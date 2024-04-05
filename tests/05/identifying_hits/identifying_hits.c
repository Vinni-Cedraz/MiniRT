#include "../../tester.h"
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
	t_sphere s = create_sphere();

	t_intersection i1 = intersection(2, &s);
	t_intersection i2 = intersection(1, &s);
	t_intersection *arr[] = {
		&i1, &i2, NULL
	};
	const t_intersection hit = _hit(arr);
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
	t_sphere s = create_sphere();
	t_intersection i1 =	intersection(1, &s);
	t_intersection i2 = intersection(-1, &s);
	t_intersection *arr[] = {
		&i1, &i2, NULL
	};
	
	const t_intersection hit = _hit(arr);
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
	t_sphere s = create_sphere();
	t_intersection i1 = intersection(-1, &s);
	t_intersection i2 = intersection(-2, &s);
	t_intersection *arr[] = { 
		&i1, &i2, NULL
	};
	const t_intersection hit = _hit(arr);
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
	t_sphere s = create_sphere();
	t_intersection i1 = intersection(5, &s);
	t_intersection i2 = intersection(7, &s);
	t_intersection i3 = intersection(-3,&s);
	t_intersection i4 = intersection(2, &s);

	t_intersection *arr[] = {
			&i1,
			&i2,
			&i3,
			&i4,
			NULL
	};

	const t_intersection hit = _hit(arr);
	cr_expect_eq(hit.t, 2);
}
