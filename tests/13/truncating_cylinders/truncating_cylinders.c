#include "../../tester.h"

// Scenario Outline : Intersecting a constrained cylinder
#define scenario                                                                                                       \
    CYAN "\nGiven cyl ← cylinder()\n"                                                                                \
         "And cyl.minimum ← 1\n"                                                                                     \
         "And cyl.maximum ← 2\n"                                                                                     \
         "And direction ← normalize(<direction>)\n"                                                                  \
         "And r ← ray(<point>, direction)\n"                                                                         \
         "When xs ← local_intersect(cyl, r)\n"                                                                       \
         "Then xs.count = <count>\n"                                                                                   \
         "Examples :\n"                                                                                                \
         " point             | direction          | count |\n"                                                         \
         " point(0, 1.5, 0)  | vector(0.1, 1, 0)  | 0\n"                                                               \
         " point(0, 3, -5)   | vector(0, 0, 1)    | 0\n"                                                               \
         " point(0, 0, -5)   | vector(0, 0, 1)    | 0\n"                                                               \
         " point(0, 2, -5)   | vector(0, 0, 1)    | 0\n"                                                               \
         " point(0, 1, -5)   | vector(0, 0, 1)    | 0\n"                                                               \
         " point(0, 1.5, -2) | vector(0, 0, 1)    | 2\n"                                                               \
         RESET

Test(truncating_cylinders, intersecting_constrained_cylinder, .description = scenario) {
	t_intersections xs;
    t_shape cyl = create_cylinder();
    t_ray r1 = {.origin = {0, 1.5, 0, POINT}, .direction = {0.1, 1, 0, VECTOR}};
    t_ray r2 = {.origin = {0, 3, -5, POINT}, .direction = {0, 0, 1, VECTOR}};
    t_ray r3 = {.origin = {0, 0, -5, POINT}, .direction = {0, 0, 1, VECTOR}};
    t_ray r4 = {.origin = {0, 2, -5, POINT}, .direction = {0, 0, 1, VECTOR}};
    t_ray r5 = {.origin = {0, 1, -5, POINT}, .direction = {0, 0, 1, VECTOR}};
    t_ray r6 = {.origin = {0, 1.5, -2, POINT}, .direction = {0, 0, 1, VECTOR}};

    set_cyl_min_max(&cyl, 1, 2);
	r1.direction = normalize(r1.direction);

	xs = intersect_shape(&cyl, &r1);
	cr_expect_eq(xs.count, 0);
	printf("xs.count -> %d\n", xs.count);
	xs = intersect_shape(&cyl, &r2);
	cr_expect_eq(xs.count, 0);
	xs = intersect_shape(&cyl, &r3);
	cr_expect_eq(xs.count, 0);
	xs = intersect_shape(&cyl, &r4);
	cr_expect_eq(xs.count, 0);
	xs = intersect_shape(&cyl, &r5);
	cr_expect_eq(xs.count, 0);
	xs = intersect_shape(&cyl, &r6);
	cr_expect_eq(xs.count, 2);
}
