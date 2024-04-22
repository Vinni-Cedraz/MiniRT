#include "../../tester.h"

// Scenario : The normal of a plane is constant everywhere
#define scenario1 CYAN \
	   "Given plane ←  create_plane()\n"                                                 \
       "When n1 ←  plane_normal_at(plane, point(0, 0, 0))\n"                      \
       "And n2 ←  plane_normal_at(plane, point(10, 0, -10))\n"                    \
       "And n3 ←  plane_normal_at(plane, point(-5, 0, 150))\n"                    \
       "Then n1 = vector(0, 1, 0)\n"                                           \
       "And n2 = vector(0, 1, 0)\n"                                            \
       "And n3 = vector(0, 1, 0)\n" RESET

Test(implementing_plane, the_normal_of_a_plane, .description = scenario1) {
  t_tuple n1;
  t_tuple n2;
  t_tuple n3;
  const t_tuple expected_vector = {0, 1, 0, VECTOR};
  const t_shape plane = create_plane();

  n1 = plane_normal_at((t_shape *)&plane, create_point(0, 0, 0));
  cr_expect_tuples_eq(n1, expected_vector);
  n2 = plane_normal_at((t_shape *)&plane, create_point(10, 0, -10));
  cr_expect_tuples_eq(n2, expected_vector);
  n3 = plane_normal_at((t_shape *)&plane, create_point(-5, 0, 150));
  cr_expect_tuples_eq(n3, expected_vector);
}

#define scenario2 CYAN                                           \
"Scenario : Intersect with a ray parallel to the plane\n"        \
"Given plane ← plane()\n"        								     \
"And r ← ray(point(0, 10, 0), vector(0, 0, 1))\n"                \
"When xs ← create_intersection(plane, r)\n"                              \
"Then xs is empty\n"RESET

Test(implementing_plane, parallel_ray_intersects_plane, .description = scenario2) {
	t_shape plane = create_plane();
	const t_ray ray = {
		.origin = {0, 0, 0, POINT},
		.direction = {0, 0, 0, VECTOR},
	};

	const t_intersections xs = intersect_shape(&plane, &ray);
	printf("%p %d\n", xs.head, xs.count);
	cr_assert_eq(xs.count, 0);
	cr_assert_eq(xs.head, NULL);
}

// Scenario : Intersect with a coplanar ray
#define scenario3 CYAN \
"Given p ← plane()\n"           \
"And r ← ray(point(0, 0, 0), vector(0, 0, 1))\n"           \
"When xs ← create_intersection(p, r)\n"           \
"Then xs is empty\n"RESET

Test(implementing_plane, coplanar_ray_intersects_plane, .description = scenario3) {
	t_shape plane = create_plane();
	const t_ray ray = {
		.origin = {0, 0, 0, POINT},
		.direction = {0, 0, 0, VECTOR},
	};
	t_intersections xs = intersect_shape(&plane, &ray);
	cr_assert_eq(xs.count, 0);
	cr_assert_eq(xs.head, NULL);
}

// Scenario : A ray intersecting a plane from above
#define scenario4 CYAN \
"Given plane ← create_plane()\n"                              \
"And r ← ray(point(0, 1, 0), vector(0, -1, 0))\n"  \
"When xs ← create_intersection(p, r)\n"                \
"Then xs.count = 1\n"                              \
"And xs[0].t = 1\n"                                \
"And xs[0].object = plane \n" RESET

Test(implementing_plane, ray_from_above_intersects_plane, .description = scenario4) {
	t_shape plane = create_plane();
	const t_ray ray = {
		.origin = {0, 1, 0, POINT},
		.direction = {0, -1, 0, VECTOR},
	};
	t_intersections xs = intersect_shape(&plane, &ray);
	cr_assert_eq(xs.count, 1);
	cr_assert_eq(xs.head[0].shape->type, PLANE);
	cr_assert_eq(xs.head[0].shape, (t_shape *)&plane);
}

// Scenario : A ray intersecting a plane from below
#define scenario5 CYAN \
"Given p ← plane()\n"       						   	     \
"And r ← ray(point(0, -1, 0), vector(0, 1, 0))\n"            \
"When xs ← create_intersection(p, r)\n"                          \
"Then xs.count = 1\n"                                        \
"And xs[0].t = 1\n"                                          \
"And xs[0].object = p\n"   RESET

Test(implementing_plane, ray_from_below_intersects_plane, .description = scenario5) {
	t_shape plane = create_plane();
	const t_ray ray = {
		.origin = {0, -1, 0, POINT},
		.direction = {0, 1, 0, VECTOR},
	};
	const t_intersections xs = intersect_shape(&plane, &ray);
	cr_expect_eq(1, xs.count);
	cr_assert_eq(xs.head->shape->type, PLANE);
	cr_expect_eq(xs.head->shape, &plane);
}
