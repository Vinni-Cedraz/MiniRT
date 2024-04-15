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
	const t_matrix T = create_translation_matrix((t_tuple){3, 4, 5, POINT}); const t_ray r2 = transform_ray(r, T);
	const t_ray expected = create_ray((t_tuple){4, 6, 8, POINT}, (t_tuple){0, 1, 0, VECTOR});

	cr_expect_tuples_eq(r2.origin, expected.origin);
	cr_expect_tuples_eq(r2.direction, expected.direction);
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

	cr_expect_tuples_eq(r2.origin, expected.origin);
	cr_expect_tuples_eq(r2.direction, expected.direction);
}
 
// Scenario : A sphere's default transformation
#define scenario3 CYAN "\nGiven s ← sphere()\n"                              \
"\nThen s.transform = identity_matrix" RESET

Test(suite, default_sphere_transformation, .description = scenario3) {
	const t_sphere s = create_sphere();
	const t_matrix expected = create_identity_matrix();

	cr_expect_eq(TRUE, matrices_eq(s._t, expected));
}

// Scenario : Changing a sphere's transformation
 #define scenario4 CYAN "\nGiven s ← sphere()\n"                         \
 "And T ← translation(2, 3, 4)\n"                                        \
 "When set_transform(s, T)\n"                                            \
 "Then s._t == T\n"                                                      \
 "Then s.inverse_t == invert_matrix(T)" RESET

 Test(suite, changing_sphere_transformation, .description = scenario4) {
 	t_sphere s = create_sphere();

	t_matrix T1 = create_translation_matrix((t_tuple){2, 3, 4, POINT});
	t_matrix inverse_T1 = invert_matrix(T1);
 	set_transform(&s, T1);
	cr_expect_eq(true, matrices_eq(s._t, T1));
	cr_expect_eq(true, matrices_eq(s.inverse_t, inverse_T1));
}

// Scenario : Intersecting a scaled sphere with a ray
#define scenario5 CYAN \
"\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n" \
"And s ← sphere()\n"                                                         \
"When s.transform = create_scaling_matrix(2, 2, 2)\n"                        \
"And xs ← intersect_sphere(s, r)\n"                                       \
"Then xs.count = 2\n"                                                        \
"And xs.head->t = 3\n"                                                       \
"And xs.next->t = 7"RESET

Test(suite, intersecting_scaled_sphere_with_a_ray, .description = scenario5) {
	const t_ray r = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	t_sphere s = create_sphere();
	const t_matrix _t = create_scaling_matrix(2, 2, 2);
	t_intersections xs;

	set_transform(&s, _t);
	// printf("scaling matrix\n");
	// print_matrix(s._t);
	// printf("inverse scaling matrix\n");
	// print_matrix(s.inverse_t);
	xs = intersect_sphere(&s, r);
	printf("%f xs.head->t\n", xs.head->t);
	printf("%f xs.head->next->t\n", xs.head->next->t);
	cr_expect_eq(xs.count, 2);
	cr_expect_eq(xs.head->t, 3);
	cr_expect_eq(xs.head->next->t, 7);
}

// Scenario : Intersecting a translated sphere with a ray
#define scenario6 CYAN  \
"\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n" \
"And s ← sphere()\n"                                                         \
"When s.transform = translation(5, 0, 0)\n"                                  \
"And xs ← intersect_sphere(s, r)\n"                                                 \
"Then xs.count = 0" RESET

Test(suite, intersecting_a_translated_sphere, .description = scenario6)
{
	t_sphere s;
	t_intersections xs;
	const t_ray	r = create_ray((t_tuple){0,0, -5, POINT}, (t_tuple){0,0,1, VECTOR});
	const t_matrix t = create_translation_matrix((t_tuple){5, 0, 0, POINT});

 	s = create_sphere();
	set_transform(&s, t);
 	xs = intersect_sphere(&s, r);
	cr_expect_eq(xs.count, 0);
}
