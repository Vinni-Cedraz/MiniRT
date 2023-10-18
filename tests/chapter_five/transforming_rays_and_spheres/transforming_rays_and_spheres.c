#include "../../tester.h"

#define suite transforming_rays_and_spheres
// Scenario : Translating a ray
#define scenario1 CYAN "\nGiven r ← ray(point(1, 2, 3), vector(0, 1, 0))\n" \
"And T ← translation(3, 4, 5)\n"                                  \
"When r2 ←  transform_ray(r, T) \n"                                     \
"Then r2.origin = point(4, 6, 8)\n"                               \
"And r2.direction = vector(0, 1, 0)"RESET

Test(suite, translating_a_ray, .description = scenario1) {
	const t_ray r = create_ray((t_tuple){1, 2, 3, POINT}, (t_tuple){0, 1, 0, VECTOR});
	const t_matrix T = create_translation_matrix((t_tuple){3, 4, 5, POINT});
	const t_ray r2 = transform_ray(r, T);
	const t_ray expected = create_ray((t_tuple){4, 6, 8, POINT}, (t_tuple){0, 1, 0, VECTOR});

	cr_expect_tuple_eq(r2.origin, expected.origin);
	cr_expect_tuple_eq(r2.direction, expected.direction);
}

// Scenario : Scaling a ray
#define scenario2 CYAN "\nGiven r ← ray(point(1, 2, 3), vector(0, 1, 0))\n"  \
"And m ← scaling(2, 3, 4)\n" \
"When r2 ← transform(r, m)\n" \
"Then r2.origin = point(2, 6, 12)\n" \
"And r2.direction = vector(0, 3, 0)" RESET

Test(suite, scaling_a_ray, .description = scenario2) {
	const t_ray r = create_ray((t_tuple){1, 2, 3, POINT}, (t_tuple){0, 1, 0, VECTOR});
	const t_matrix m = create_scaling_matrix(2, 3, 4);
	const t_ray r2 = transform_ray(r, m);
	const t_ray expected = create_ray((t_tuple){2, 6, 12, POINT}, (t_tuple){0, 3, 0, VECTOR});

	cr_expect_tuple_eq(r2.origin, expected.origin);
	cr_expect_tuple_eq(r2.direction, expected.direction);
}
	
// Scenario : A sphere's default transformation
#define scenario3 CYAN "\nGiven s ← sphere()\n"                              \
"\nThen s.transform = identity_matrix" RESET

Test(suite, default_sphere_transformation, .description = scenario3) {
	const t_sphere s = create_sphere();
	const t_matrix expected = create_identity_matrix();

	cr_expect_tuple_eq(s.transform, expected);
}

// Scenario : Changing a sphere's transformation
#define scenario4 CYAN "\nGiven s ← sphere()\n"                              \
"And T ← translation(2, 3, 4)\n"                                             \
"When s.transform = T\n"                                                 \
"Then s.transform == T" RESET

Test(suite, changing_sphere_transformation, .description = scenario4) {
	const t_sphere s = create_sphere();
	s.transform = create_translation_matrix((t_tuple){2, 3, 4, POINT});

	cr_expect_tuple_eq(s.transform, create_translation_matrix((t_tuple){2, 3, 4, POINT}));
}

// Scenario : Intersecting a scaled sphere with a ray
#define scenario5 CYAN\n \
"Given r ← ray(point(0, 0, -5), vector(0, 0, 1))\n" \
"And s ← sphere()\n"                                                         \
"When s.transform = create_scaling_matrix(2, 2, 2)\n"                        \
"And xs ← intersect(s, r)\n"                                                 \
"Then xs.count = 2\n"                                                        \
"And xs.head->t = 3\n"                                                       \
"And xs.next->t = 7"RESET


// Scenario : Intersecting a translated sphere with a ray
#define scenario6 CYAN\n  \
"\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n" \
"And s ← sphere()\n"                                                         \
"When s.transform = translation(5, 0, 0)\n"                                  \
"And xs ← intersect(s, r)\n"                                                 \
"Then xs.count = 0" RESET
