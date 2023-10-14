#include "tester.h"

// Scenario : A ray intersects a sphere at two points
#define scenario1 CYAN "\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n" \
						"And s ← sphere()\n" \
						"When xs ← intersect(s, r)\n" \
						"Then xs.count = 2\n" \
						"And xs[0] = 4.0\n" \
						"And xs[1] = 6.0\n" RESET

Test(intersecting_rays, intersects_at_two_points, .description = scenario1) {
	const t_ray r = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersect(s, r);

	cr_expect_eq(intersect.count == 2);
	cr_expect_eq(TRUE, floats_eq(intersect.list.value == 4.0));
	cr_expect_eq(TRUE, floats_eq(intersect.list.next.value == 4.0));
}
