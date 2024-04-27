#include "../../tester.h"

// Scenario Outline: The normal vector on a cylinder's end caps
#define scenario1 CYAN \
"Given cyl ← cylinder()\n"                         \
"And cyl.minimum ← 1\n"                            \
"And cyl.maximum ← 2\n"                            \
"And cyl.closed ← true\n"                          \
"When n ← local_normal_at(cyl, <point>)\n"         \
"Then n = <normal>"RESET                           \

// 1 | point(0, 1, 0) 	| vector(0, -1, 0) |
Test(capped_cylinders, finding_caps_normal1, .description = scenario1) {
  t_shape cyl = create_cylinder();
  const t_tuple point = {0, 1, 0, POINT};
  const t_tuple expected_normal = {0, -1, 0, VECTOR};
  t_tuple normal;

  cyl.closed = TRUE;
  set_cyl_min_max(&cyl, 1, 2);
  normal = cylinder_normal_at((t_shape *)&cyl, point);
  print_tuple(normal);
  print_tuple(expected_normal);
  cr_expect_tuples_eq(normal, expected_normal);
}

// 2 | point(0.5, 1, 0)	| vector(0, -1, 0) |
Test(capped_cylinders, finding_caps_normal2) {
  t_shape cyl = create_cylinder();
  const t_tuple point = {0.5, 1, 0, POINT};
  const t_tuple expected_normal = {0, -1, 0, VECTOR};
  t_tuple normal;

  cyl.closed = TRUE;
  set_cyl_min_max(&cyl, 1, 2);
  normal = cylinder_normal_at((t_shape *)&cyl, point);
  print_tuple(expected_normal);
  cr_expect_tuples_eq(normal, expected_normal);
}


// 3 | point(0, 1, 0.5)	| vector(0, -1, 0) |
Test(capped_cylinders, finding_caps_normal3) {
  t_shape cyl = create_cylinder();
  const t_tuple point = {0, 1, 0.5, POINT};
  const t_tuple expected_normal = {0, -1, 0, VECTOR};
  t_tuple normal;

  cyl.closed = TRUE;
  set_cyl_min_max(&cyl, 1, 2);
  normal = cylinder_normal_at((t_shape *)&cyl, point);
  cr_expect_tuples_eq(normal, expected_normal);
}

// 4 | point(0, 2, 0)		| vector(0, 1, 0)  |
Test(capped_cylinders, finding_caps_normal4) {
  t_shape cyl = create_cylinder();
  const t_tuple point = {0, 2, 0, POINT};
  const t_tuple expected_normal = {0, 1, 0, VECTOR};
  t_tuple normal;

  cyl.closed = TRUE;
  set_cyl_min_max(&cyl, 1, 2);
  normal = cylinder_normal_at((t_shape *)&cyl, point);
  cr_expect_tuples_eq(normal, expected_normal);
}

// 5 | point(0.5, 2, 0)	| vector(0, 1, 0)  |
Test(capped_cylinders, finding_caps_normal5) {
  t_shape cyl = create_cylinder();
  const t_tuple point = {0.5, 2, 0, POINT};
  const t_tuple expected_normal = {0, 1, 0, VECTOR};
  t_tuple normal;

  cyl.closed = TRUE;
  set_cyl_min_max(&cyl, 1, 2);
  normal = cylinder_normal_at((t_shape *)&cyl, point);
  cr_expect_tuples_eq(normal, expected_normal);
}

// 6 | point(0, 2, 0.5)	| vector(0, 1, 0)  |
Test(capped_cylinders, finding_caps_normal6) {
  t_shape cyl = create_cylinder();
  const t_tuple point = {0, 2, 0.5, POINT};
  const t_tuple expected_normal = {0, 1, 0, VECTOR};
  t_tuple normal;

  cyl.closed = TRUE;
  set_cyl_min_max(&cyl, 1, 2);
  normal = cylinder_normal_at((t_shape *)&cyl, point);
  cr_expect_tuples_eq(normal, expected_normal);
}
