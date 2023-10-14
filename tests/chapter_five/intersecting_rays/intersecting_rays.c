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
	cr_expect_eq(TRUE, floats_eq(intersect.list.value[Z] == 4.0));
	cr_expect_eq(TRUE, floats_eq(intersect.list.next->value[Z] == 4.0));
}

// Scenario : A ray intersects a sphere at a tangent
#define scenario2 CYAN \
				  "\nGiven r ← ray(point(0, 1, -5), vector(0, 0, 1))\n" \
				  "And s ← sphere()\n"                                \
				  "When xs ← intersect(s, r)\n"                       \
				  "Then xs.count = 2\n"                               \
				  "And xs[0] = 5.0\n"                                 \
				  "And xs[1] = 5.0"            RESET

Test(intersecting_rays, tangent_intersection, .description = scenario2) {
	const t_ray r = create_ray((t_tuple){0, 1, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersect(s, r);

	cr_expect_eq(intersect.count == 2);
	cr_expect_eq(TRUE, floats_eq(intersect.list.value[Z] == 5.0));
}

// Scenario : A ray misses a sphere
#define scenario3 CYAN \
				 "Given r ← ray(point(0, 2, -5), vector(0, 0, 1))\n" \
				 "And s ← sphere()\n" \
				 "When xs ← intersect(s, r)\n" \
				 "Then xs.count = 0" RESET

Test(intersecting_rays, intersects_nothing, .description = scenario3) {
	const t_ray r = create_ray((t_tuple){0, 2, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersect(s, r);

	cr_expect_eq(intersect.count == 0);
}

// Scenario : A ray originates inside a sphere
#define scenario4 CYAN \
					"Given r ← ray(point(0, 0, 0), vector(0, 0, 1))\n" \
					"And s ← sphere()\n" \
					"When xs ← intersect(s, r)\n" \
					"Then xs.count = 2\n" \
					"And xs[0] = -1.0\n" \
					"And xs[1] = 1.0" RESET
Test(intersecting_rays, ray_starts_inside_of_a_sphere, .description = scenario4) {
	const t_ray r = create_ray((t_tuple){0, 0, 0, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersect(s, r);

	cr_expect_eq(intersect.count == 2);
	cr_expect_eq(TRUE, floats_eq(intersect.list.value[Z] == -1.0));
	cr_expect_eq(TRUE, floats_eq(intersect.list.next->value[Z] == 1.0));
}

