#include "tester.h"

// Scenario : The normal of a plane is constant everywhere
#define scenario1 CYAN \
	   "Given p ← create_plane()\n"                                                 \
       "When n1 ← plane_normal_at(p, point(0, 0, 0))\n"                      \
       "And n2 ← plane_normal_at(p, point(10, 0, -10))\n"                    \
       "And n3 ← plane_normal_at(p, point(-5, 0, 150))\n"                    \
       "Then n1 = vector(0, 1, 0)\n"                                           \
       "And n2 = vector(0, 1, 0)\n"                                            \
       "And n3 = vector(0, 1, 0)\n" RESET

Test(implementing_plane, the_normal_of_a_plane, .description = scenario1) {
  const t_plane p = create_plane();
  t_tuple n1;
  t_tuple n2;
  t_tuple n3;
  const t_tuple expected_vector = {0, 1, 0, VECTOR};

  plane_normal_at(&p, (t_tuple){0, 0, 0, POINT},n1);
  cr_expect_tuples_eq(n1, expected_vector);
  plane_normal_at(&p, (t_tuple){0, 0, 0, POINT},n2);
  cr_expect_tuples_eq(n2, expected_vector);
  plane_normal_at(&p, (t_tuple){0, 0, 0, POINT},n3);
  cr_expect_tuples_eq(n3, expected_vector);
}


