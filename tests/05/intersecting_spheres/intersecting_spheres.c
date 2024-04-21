#include "../../tester.h"

// Scenario : A ray intersects a sphere at two points
#define scenario1 CYAN "\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n" \
						"And s ← sphere()\n" \
						"When inters ← inter(s, r)\n" \
						"Then inters.count = 2\n" \
						"And inters.this_obj_intersections->t = 4.0\n" \
						"And inters.this_obj_intersections->next->t = 6.0\n" RESET

Test(intersecting_spheres, intersects_at_two_points, .description = scenario1) {
	const t_ray r = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	t_shape s = create_sphere();
	const t_intersections inter = intersect_shape(&s, &r);

	cr_expect_eq(inter.count, 2);
	cr_expect_eq(TRUE, doubles_eq(inter.head->t, 4.0));
	cr_expect_eq(TRUE, doubles_eq(inter.head->next->t, 6.0));
}

// Scenario : A ray intersects a sphere at a tangent
#define scenario2 CYAN \
				  "\nGiven r ← ray(point(0, 1, -5), vector(0, 0, 1))\n" \
				  "And s ← sphere()\n"                                \
				  "When inter ← inter(s, r)\n"                       \
				  "Then inter.count = 1\n"                               \
				  "And inter.this_obj_intersections->t = 5.0\n"                                 \

Test(intersecting_spheres, tangent_intersection, .description = scenario2) {
	const t_ray r = create_ray((t_tuple){0, 1, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	t_shape s = create_sphere();
	const t_intersections inter = intersect_shape(&s, &r);

	cr_expect_eq(inter.count, 2);
	cr_expect_eq(TRUE, doubles_eq(inter.head->t, 5.0));
	cr_expect_eq(TRUE, doubles_eq(inter.head->next->t, 5.0));
}

// Scenario : A ray misses a sphere
#define scenario3 CYAN \
				 "\nGiven r ← ray(point(0, 2, -5), vector(0, 0, 1))\n" \
				 "And s ← sphere()\n" \
				 "When i ← inter(s, r)\n" \
				 "Then i.count == 0\n" \
				 "And i.this_obj_intersections == NULL" RESET

Test(intersecting_spheres, intersects_nothing, .description = scenario3) {
	const t_ray r = create_ray((t_tuple){0, 2, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	t_shape s = create_sphere();
	const t_intersections inter = intersect_shape(&s, &r);

	cr_expect_eq(inter.count, 0);
}

// Scenario : A ray originates inside a sphere
#define scenario4 CYAN \
					"\nGiven r ← ray(point(0, 0, 0), vector(0, 0, 1))\n" \
					"And s ← sphere()\n" \
					"When i ← inter(s, r)\n" \
					"Then i.count = 2\n" \
					"And i.this_obj_intersections->t = -1.0\n" \
					"And i.this_obj_intersections->next->t = 1.0" RESET

Test(intersecting_spheres, ray_starts_inside_of_a_sphere, .description = scenario4) {
	const t_ray r = create_ray((t_tuple){0, 0, 0, POINT}, (t_tuple){0, 0, 1, VECTOR});
	t_shape s = create_sphere();
	t_intersections inter = intersect_shape(&s, &r);

	cr_expect_eq(inter.count, 2);
	cr_expect_eq(TRUE, doubles_eq(inter.head->t, -1.0));
	cr_expect_eq(TRUE, doubles_eq(inter.head->next->t, 1.0));
}

// Scenario : A sphere is behind a ray
#define scenario5 CYAN \
				"\nGiven r ← ray(point(0, 0, 5), vector(0, 0, 1))And s ← sphere()\n" \
				"When i ← intersect_shape(s, r)\n" \
				"Then i.count == 2\n" \
				"And i.this_obj_intersections->t == -6.0\n" \
				"And i.this_obj_intersections->next->t == -4.0\n" RESET

Test(intersecting_spheres, sphere_is_behind_the_ray, .description = scenario5) {
	const t_ray r = create_ray((t_tuple){0, 0, 5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	t_shape s = create_sphere();
	const t_intersections inter = intersect_shape(&s, &r);

	cr_expect_eq(inter.count, 2);
	if (doubles_eq(inter.head->t, -6.0) == FALSE)
		printf(RED"inter.head->t %f\n", inter.head->t);
	if (doubles_eq(inter.head->next->t, -4.0) == FALSE)
		printf(RED"inter.head->next->t %f\n"RESET, inter.head->next->t);
	cr_expect_eq(TRUE, doubles_eq(inter.head->t, -6.0));
	cr_expect_eq(TRUE, doubles_eq(inter.head->next->t, -4.0));
}

#define scenario6 CYAN \
		"\nGiven r <- ray{.origin = (0, 0, -2), direction = (0, 0.240192, 0.970725)\n" \
		"When i <- intersect_shape(sphere, r)\n" \
		"Then i.count = 2\n"               \
		"And i.this_obj_intersections[0].t = sqrt(3)\n" \
		"And i.this_obj_intersections[1].t = sqrt(3)\n"RESET

Test(intersecting_spheres, the_ray_is_diagonal_and_tangencies_the_sphere, .description = scenario6) {
	const t_tuple ray_origin = create_point(0, 0, -2);
	const t_tuple intersection_t = create_point(0, 0.8660254037844, -0.5);
	const t_tuple direction = subtract_tuples(intersection_t, ray_origin);
	const t_ray r = create_ray(ray_origin, normalize(direction));
	t_shape s = create_sphere();
	const t_intersections i = intersect_shape(&s, &r);
	if (low_precision_doubles_eq(i.head->t, sqrt(3)) == FALSE)
		printf(RED"inter.head->t %f\n", i.head->t);
	if (low_precision_doubles_eq(i.head->next->t, sqrt(3)) == FALSE)
		printf(RED"inter.head->next->t %f\n"RESET, i.head->next->t);
	cr_expect_eq(TRUE, low_precision_doubles_eq(i.head->t, sqrt(3)));
	cr_expect_eq(TRUE, low_precision_doubles_eq(i.head->next->t, sqrt(3)));
}
