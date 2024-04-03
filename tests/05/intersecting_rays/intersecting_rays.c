#include "../../tester.h"

// Scenario : A ray intersects a sphere at two points
#define scenario1 CYAN "\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n" \
						"And s ← sphere()\n" \
						"When inters ← intersect(s, r)\n" \
						"Then inters.count = 2\n" \
						"And inters.head->t = 4.0\n" \
						"And inters.head->next->t = 6.0\n" RESET

Test(intersecting_rays, intersects_at_two_points, .description = scenario1) {
	const t_ray r = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersection((void *)&s, r);

	cr_expect_eq(intersect.count, 2);
	cr_expect_eq(TRUE, doubles_eq(intersect.head->t, 4.0));
	cr_expect_eq(TRUE, doubles_eq(intersect.head->next->t, 6.0));
}

// Scenario : A ray intersects a sphere at a tangent
#define scenario2 CYAN \
				  "\nGiven r ← ray(point(0, 1, -5), vector(0, 0, 1))\n" \
				  "And s ← sphere()\n"                                \
				  "When inter ← intersect(s, r)\n"                       \
				  "Then inter.count = 1\n"                               \
				  "And inter.head->t = 5.0\n"                                 \

Test(intersecting_rays, tangent_intersection, .description = scenario2) {
	const t_ray r = create_ray((t_tuple){0, 1, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersection((void *)&s, r);

	cr_expect_eq(intersect.count, 1);
	cr_expect_eq(TRUE, doubles_eq(intersect.head->t, 5.0));
}

// Scenario : A ray misses a sphere
#define scenario3 CYAN \
				 "\nGiven r ← ray(point(0, 2, -5), vector(0, 0, 1))\n" \
				 "And s ← sphere()\n" \
				 "When i ← intersect(s, r)\n" \
				 "Then i.count == 0\n" \
				 "And i.head == NULL" RESET

Test(intersecting_rays, intersects_nothing, .description = scenario3) {
	const t_ray r = create_ray((t_tuple){0, 2, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersection((void *)&s, r);

	cr_expect_eq(intersect.count, 0);
	cr_expect_eq(intersect.head, NULL);
}

// Scenario : A ray originates inside a sphere
#define scenario4 CYAN \
					"\nGiven r ← ray(point(0, 0, 0), vector(0, 0, 1))\n" \
					"And s ← sphere()\n" \
					"When i ← intersect(s, r)\n" \
					"Then i.count = 2\n" \
					"And i.head->t = -1.0\n" \
					"And i.head->next->t = 1.0" RESET

Test(intersecting_rays, ray_starts_inside_of_a_sphere, .description = scenario4) {
	const t_ray r = create_ray((t_tuple){0, 0, 0, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersection((void *)&s, r);

	cr_expect_eq(intersect.count, 2);
	cr_expect_eq(TRUE, doubles_eq(intersect.head->t, -1.0));
	cr_expect_eq(TRUE, doubles_eq(intersect.head->next->t, 1.0));
}

// Scenario : A sphere is behind a ray
#define scenario5 CYAN \
				"\nGiven r ← ray(point(0, 0, 5), vector(0, 0, 1))And s ← sphere()\n" \
				"When i ← intersect(s, r)\n" \
				"Then i.count == 2\n" \
				"And i.head->t == -6.0\n" \
				"And i.head->next->t == -4.0\n" RESET

Test(intersecting_rays, sphere_is_behind_the_ray, .description = scenario5) {
	const t_ray r = create_ray((t_tuple){0, 0, 5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersection((void *)&s, r);

	cr_expect_eq(intersect.count, 2);
	if (doubles_eq(intersect.head->t, -6.0) == FALSE)
		printf(RED"intersect.head->t %f\n", intersect.head->t);
	if (doubles_eq(intersect.head->next->t, -4.0) == FALSE)
		printf(RED"intersect.head->next->t %f\n"RESET, intersect.head->next->t);
	cr_expect_eq(TRUE, doubles_eq(intersect.head->t, -6.0));
	cr_expect_eq(TRUE, doubles_eq(intersect.head->next->t, -4.0));
}
