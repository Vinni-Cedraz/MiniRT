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

// Scenario : A sphere is behind a ray
#define scenario5 CYAN \
				"Given r ← ray(point(0, 0, 5), vector(0, 0, 1))And s ← sphere()\n" \
				"When xs ← intersect(s, r)\n" \
				"Then xs.count = 2\n" \
				"And xs[0] = -6.0\n" \
				"And xs[1] = -4.0\n" RESET

Test(intersecting_rays, sphere_is_behind_the_ray, .description = scenario5) {
	const t_ray r = create_ray((t_tuple){0, 0, 0, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersect(s, r);

	cr_expect_eq(intersect.count == 2);
	cr_expect_eq(TRUE, floats_eq(intersect.list.value[Z] == -6.0));
	cr_expect_eq(TRUE, floats_eq(intersect.list.next->value[Z] == -4.0));
}

// Scenario: calculating the discriminant (intersection between ray and sphere)
#define scenario6 CYAN \
			"sphere_to_ray ← ray.origin - point(0, 0, 0)\n" \
			"a ← dot(ray.direction, ray.direction)\n" \
			"b ← 2 * dot(ray.direction, sphere_to_ray)\n" \
			"c ← dot(sphere_to_ray, sphere_to_ray) - 1\n" \
			"discriminant ← b² - 4 * a * c\n" \
			"if discriminant < 0 then\n" \
			"return ()\n" \
			"end if\n" \
			"t1 ← (-b - √(discriminant)) / (2 * a)\n" \
			"t2 ← (-b + √(discriminant)) / (2 * a)\n" \
			"return (t1, t2)"

// Copilot, you should calculate the discriminant, take a look at scenario6 description!
Test(intersecting_rays, discriminant, .description = scenario6) {
	const t_ray r = create_ray((t_tuple){0, 0, 0, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersect(s, r);
	const double a = dot(r.direction, r.direction);
	const double b = 2 * dot(r.direction, s.origin);
	const double c = dot(s.origin, s.origin) - 1;
	const double discriminant = pow(b, 2) - 4 * a * c;

	cr_expect_eq(discriminant > 0);
	cr_expect_eq(intersect.count == 2);
	// cr_expect_eq(TRUE, floats_eq(discriminant == 4.0));
	// cr_expect_eq(TRUE, floats_eq(intersect.list.value[Z] == -1.0));
	// cr_expect_eq(TRUE, floats_eq(intersect.list.next->value[Z] == 1.0));
}
