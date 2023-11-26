#include "tester.h"

// Scenario Outline: A ray misses a cylinder
#define scenario1                                                                                                      \
    CYAN "\nGiven cyl ←  cylinder()\n"                                                                                 \
         "And direction ←  normalize(<direction>)\n"                                                                 \
         "And r ←  ray(<origin>, direction)\n"                                                                       \
         "When xs ←  local_intersect(cyl, r)\n"                                                                      \
         "Then xs.count = 0\n" RESET

Test(intersect_cylinder, ray_misses_a_cylinder, .description = scenario1) {
    t_cylinder cyl = create_cylinder();
    t_intersection xs;
    const t_ray r1 = {{1, 0, 0, POINT}, {0, 1, 0, VECTOR}};
    const t_ray r2 = {{0, 0, 0, POINT}, {0, 1, 0, VECTOR}};
    t_ray r3 = {{0, 0, -5, POINT}, {1, 1, 1, VECTOR}};

    xs = create_intersection(&cyl, r1);
    cr_expect_eq(xs.count, 0);
    xs = create_intersection(&cyl, r2);
    cr_expect_eq(xs.count, 0);
    xs = create_intersection(&cyl, r3);
    cr_expect_eq(xs.count, 0);
}

// Scenario Outline: A ray strikes a cylinder
#define scenario2                                                                                                      \
    CYAN "\nGiven cyl ←  cylinder()\n"                                                                                 \
         "And direction ←  normalize(<direction>)\n"                                                                 \
         "And r ←  ray(<origin>, direction)\n"                                                                       \
         "When xs ←  local_intersect(cyl, r)\n"                                                                      \
         "Then xs.count = 2\n"                                                                                         \
         "And xs[0].t = <t0>\n"                                                                                        \
         "And xs[1].t = <t1>" RESET

Test(intersect_cylinder, ray_strikes_cylinder, .description = scenario2) {
    t_intersection xs;
    t_cylinder cyl = create_cylinder();
    const t_ray r1 = {{1, 0, -5, POINT}, {0, 0, 1, VECTOR}};
    const t_ray r2 = {{0, 0, -5, POINT}, {0, 0, 1, VECTOR}};
    t_ray r3 = {{0.5, 0, -5, POINT}, {0.1, 1, 1, VECTOR}};

	normalize(r3.direction, r3.direction);
    const float first_t1 = 5;
    const float first_t2 = 5;
    const float second_t1 = 4;
    const float second_t2 = 6;
    const float third_t1 = 6.8080;
    const float third_t2 = 7.0887;

    xs = create_intersection(&cyl, r1);
	cr_assert_neq(xs.head, NULL);
    cr_expect_eq(xs.head->t, first_t1);
    cr_expect_eq(xs.head->next->t, first_t2);
    xs = create_intersection(&cyl, r2);
	cr_assert_neq(xs.head, NULL);
    cr_expect_eq(xs.head->t, second_t1);
    cr_expect_eq(xs.head->next->t, second_t2);
    xs = create_intersection(&cyl, r3);
	cr_assert_neq(xs.head, NULL);
    cr_expect_eq(floats_eq(xs.head->t, third_t1), TRUE);
    cr_expect_eq(floats_eq(xs.head->next->t, third_t2), TRUE);
}
