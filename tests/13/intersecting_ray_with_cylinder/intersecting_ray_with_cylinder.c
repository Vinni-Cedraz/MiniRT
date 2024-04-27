#include "../../tester.h"

// Scenario Outline: A ray misses a cylinder
#define scenario1                                                                                                      \
    CYAN "\nGiven cyl ←  cylinder()\n"                                                                                 \
         "And direction ←  normalize(<direction>)\n"                                                                 \
         "And r ←  ray(<origin>, direction)\n"                                                                       \
         "When xs ←  intersect_cylinder(cyl, r)\n"                                                                      \
         "Then xs.count = 0\n" RESET

Test(intersect_cylinder, ray_misses_a_cylinder, .description = scenario1) {
    t_shape cyl = create_cylinder();
    t_intersections xs;
    const t_ray r1 = {{1, 0, 0, POINT}, {0, 1, 0, VECTOR}};
    const t_ray r2 = {{0, 0, 0, POINT}, {0, 1, 0, VECTOR}};
    t_ray r3 = {{0, 0, -5, POINT}, {1, 1, 1, VECTOR}};

    xs = intersect_shape(&cyl, &r1);
    cr_expect_eq(xs.count, 0);
    xs = intersect_shape(&cyl, &r2);
    cr_expect_eq(xs.count, 0);
    xs = intersect_shape(&cyl, &r3);
    cr_expect_eq(xs.count, 0);
}

// Scenario Outline: A ray strikes a cylinder
#define scenario2                                                                                                      \
    CYAN "\nGiven cyl ←  cylinder()\n"                                                                                 \
         "And direction ←  normalize(<direction>)\n"                                                                 \
         "And r ←  ray(<origin>, direction)\n"                                                                       \
         "When xs ←  intersect_cylinder(cyl, r)\n"                                                                      \
         "Then xs.count = 2\n"                                                                                         \
         "And xs[0].t = <t0>\n"                                                                                        \
         "And xs[1].t = <t1>" RESET

Test(intersect_cylinder, ray_strikes_cylinder, .description = scenario2) {
    t_intersections xs;
    t_shape cyl = create_cylinder();
    const t_ray r1 = {{1, 0, -5, POINT}, {0, 0, 1, VECTOR}};
    const t_ray r2 = {{0, 0, -5, POINT}, {0, 0, 1, VECTOR}};
    t_ray r3 = {{0.5, 0, -5, POINT}, {0.1, 1, 1, VECTOR}};

	r3.direction = normalize(r3.direction);
    const double first_t1 = 5;
    const double first_t2 = 5;
    const double second_t1 = 4;
    const double second_t2 = 6;
    const double third_t1 = 6.80798;
    const double third_t2 = 7.08872;

    xs = intersect_shape(&cyl, &r1);
	cr_assert_neq(xs.head, NULL);
    cr_expect_eq(xs.head->t, first_t1);
    cr_expect_eq(xs.head->next->t, first_t2);
    xs = intersect_shape(&cyl, &r2);
	cr_assert_neq(xs.head, NULL);
    cr_expect_eq(xs.head->t, second_t1);
    cr_expect_eq(xs.head->next->t, second_t2);
    xs = intersect_shape(&cyl, &r3);
	cr_assert_neq(xs.head, NULL);
    cr_expect_eq(doubles_eq(xs.head->t, third_t1), TRUE);
    cr_expect_eq(doubles_eq(xs.head->next->t, third_t2), TRUE);
}

#define scenario3                                                                                                    \
    CYAN "\nGiven cyl ←  cylinder()\n"                                                                               \
         "And direction ←  normalize(<direction>)\n"                                                                 \
         "And r ←  ray(<origin>, direction)\n"                                                                       \
         "When xs ←  intersect_cylinder(cyl, r)\n"                                                                   \
         "Then t1 = 9 and t2 = 11" RESET

Test(intersect_cylinder, intersection_at_origin, .description = scenario3) {
	t_intersections xs;
	t_shape cyl = create_cylinder();
	t_ray ray = {{0, 0, 10, POINT}, {0, 0, -1, VECTOR}};
	ray.direction = normalize(ray.direction);

	const double t1 = 9;
	const double t2 = 11;
    xs = intersect_shape(&cyl, &ray);
	cr_assert_neq(xs.head, NULL);
    cr_expect_eq(xs.head->t, t1); cr_expect_eq(xs.head->next->t, t2);
}

#define scenario4                                                                                                      \
    CYAN "\nGiven cyl ←  cylinder()\n"                                                                                 \
		 "And rotate cylinder 30 degrees on x axis\n" 																   \
		 "And ray = {0, 0, -10, POINT}, {0, 0, 1, VECTOR}\n"                                                           \
         "When xs ←  intersect_cylinder(cyl, r)\n"                                                                     \
         "Then t1 == 9.15470\n" 																			   \
		 "and t2 == 10.84530" RESET

Test(intersect_cylinder, intersect_rotated_x_cylinder_at_origin_30degrees, .description = scenario4) {
	t_intersections xs;
	t_shape cyl = create_cylinder();
	set_transform((t_shape *)&cyl, create_x_rotation_matrix(M_PI/6));
	t_ray ray = {{0, 0, -10, POINT}, {0, 0, 1, VECTOR}};
	ray.direction = normalize(ray.direction);

	const double t1 = 9.15470;
	const double t2 = 10.84530;
    xs = intersect_shape(&cyl, &ray);
	cr_assert_neq(xs.head, NULL);
	// printf("%f\n", xs.head->t);
	// printf("%f\n", xs.head->next->t);
    cr_expect_eq(xs.head->t, t1);
    cr_expect_eq(xs.head->next->t, t2);
}

#define scenario5                                                                                                      \
    CYAN "\nGiven cyl ←  cylinder()\n"                                                                                 \
		 "And rotate cylinder 60 degrees on x axis\n" 																   \
		 "And ray = {0, 0, -10, POINT}, {0, 0, 1, VECTOR}\n"                                                           \
         "When xs ←  intersect_cylinder(cyl, r)\n"                                                                     \
         "Then t1 == 8 and t2 == 12" RESET

Test(intersect_cylinder, intersect_rotated_x_cylinder_at_origin_60degrees, .description = scenario5) {
	t_intersections xs;
	t_shape cyl = create_cylinder();
	set_transform((t_shape *)&cyl, create_x_rotation_matrix(M_PI/3));
	t_ray ray = {{0, 0, -10, POINT}, {0, 0, 1, VECTOR}};
	ray.direction = normalize(ray.direction);

	const double t1 = 8;
	const double t2 = 12;
    xs = intersect_shape(&cyl, &ray);
	cr_assert_neq(xs.head, NULL);
	// printf("%f\n", xs.head->t);
	// printf("%f\n", xs.head->next->t);
	// print_matrix(cyl._t);
	// print_matrix(cyl.inverse_t);
	// print_matrix(mult_matrices(cyl._t, cyl.inverse_t));
    cr_expect_eq(xs.head->t, t1);
    cr_expect_eq(xs.head->next->t, t2);
}
