#include "tester.h"

#define SQRT_OF_3 1.7320

// Scenario : The normal on a sphere at a point on the x axis
#define scenario1 CYAN                 		          \
"\nGiven s ← create_sphere()\n"						  \
"When n ← normal_at(s, point(1, 0, 0))\n"             \
"Then n = vector(1, 0, 0)"RESET

Test(surface_normals, normal_at_x_axial_point, .description = scenario1) {
	t_sphere s;
	t_tuple normal;
	const t_tuple p = {1, 0, 0, POINT};

	s = create_sphere();
	normal_at(s, p, normal);
	cr_expect_tuple_eq(normal, (t_tuple){1, 0, 0, VECTOR});
}

// Scenario : The normal on a sphere at a point on the y axis
#define scenario2 CYAN                                \
"\nGiven s ← create_sphere()\n"                       \
"When n ← normal_at(s, point(0, 1, 0))\n"             \
"Then n = vector(0, 1, 0)" RESET

Test(surface_normals, normal_at_y_axial_point, .description = scenario2) {
	t_sphere s;
	t_tuple normal;
	const t_tuple p = {0, 1, 0, POINT};

	normal_at(s, p, normal);
	cr_expect_tuple_eq(normal, (t_tuple){0, 1, 0, VECTOR});
}

//Scenario : The normal on a sphere at a point on the z axis
#define scenario3 CYAN                                \
"\nGiven s ← create_sphere()\n"                              \
"When n ← normal_at(s, point(0, 0, 1))\n"             \
"Then n = vector(0, 0, 1)"RESET                       

Test(surface_normals, normal_at_z_axial_point, .description = scenario3) {
	t_sphere s;
	t_tuple normal;
	const t_tuple p = {0, 0, 1, POINT};

	normal_at(s, p, normal);
	cr_expect_tuple_eq(normal, (t_tuple){0, 0, 1, VECTOR});
}

// Scenario : The normal on a sphere at a nonaxial point
#define scenario4 CYAN                                \
"\nGiven s ← create_sphere()\n"                       \
"When n ← normal_at(s, point(√3/3, √3/3, √3/3))\n"    \
"Then n = vector(√3/3, √3/3, √3/3)\n"

Test(surface_normals, normal_at_nonaxial_point, .description = scenario4) {
	t_sphere s;
	t_tuple normal;
	const t_tuple p = {SQRT_OF_3 / 3, SQRT_OF_3 / 3, SQRT_OF_3 / 3, POINT};

	normal_at(s, p, normal);
	cr_expect_tuple_eq(normal, (t_tuple){SQRT_OF_3 / 3, SQRT_OF_3 / 3, SQRT_OF_3 / 3, VECTOR});
}

// Scenario : The normal is a normalized vector
#define scenario5 CYAN                                   \
"\nGiven s ← sphere()\n"                                 \
"When n ← normal_at(s, point(√3/3, √3/3, √3/3))\n"       \
"Then n = normalize(n)" RESET

Test(surface_normals, the_normal_is_normalized, .description = scenario5) {
	t_sphere s;
	t_tuple actual_normal;
	t_tuple expected_normal;

	const t_tuple p = {SQRT_OF_3 / 3, SQRT_OF_3 / 3, SQRT_OF_3 / 3, POINT};
	normal_at(s, p, actual_normal);
	normalize(actual_normal, expected_normal);
	cr_expect_tuple_eq(actual_normal, expected_normal);
}
