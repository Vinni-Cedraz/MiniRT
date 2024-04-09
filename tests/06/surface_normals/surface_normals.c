#include "../../tester.h"

// Scenario : The normal on a sphere at a point on the x axis
#define scenario1 CYAN                 		          \
"\nGiven s ← create_sphere()\n"						  \
"When n ← sphere_normal_at(s, point(1, 0, 0))\n"             \
"Then n = vector(1, 0, 0)"RESET

Test(surface_normals, sphere_normal_at_x_axial_point, .description = scenario1) {
	t_sphere s = create_sphere();
	t_tuple normal;
	const t_tuple p = {1, 0, 0, POINT};

	normal = sphere_normal_at(&s, p);
	print_tuple(normal);
	cr_expect_tuples_eq(normal, (t_tuple){1, 0, 0, VECTOR});
}

// Scenario : The normal on a sphere at a point on the y axis
#define scenario2 CYAN                                \
"\nGiven s ← create_sphere()\n"                       \
"When n ← sphere_normal_at(s, point(0, 1, 0))\n"             \
"Then n = vector(0, 1, 0)" RESET

Test(surface_normals, sphere_normal_at_y_axial_point, .description = scenario2) {
	t_tuple normal;
	t_sphere s = create_sphere();
	const t_tuple p = {0, 1, 0, POINT};

	normal = sphere_normal_at(&s, p);
	cr_expect_tuples_eq(normal, (t_tuple){0, 1, 0, VECTOR});
}

//Scenario : The normal on a sphere at a point on the z axis
#define scenario3 CYAN                                \
"\nGiven s ← create_sphere()\n"                              \
"When n ← sphere_normal_at(s, point(0, 0, 1))\n"             \
"Then n = vector(0, 0, 1)"RESET                       

Test(surface_normals, sphere_normal_at_z_axial_point, .description = scenario3) {
	t_sphere s = create_sphere();
	t_tuple		normal;
	const t_tuple p = {0, 0, 1, POINT};

	normal = sphere_normal_at(&s, p);
	cr_expect_tuples_eq(normal, (t_tuple){0, 0, 1, VECTOR});
}

// Scenario : The normal on a sphere at a nonaxial point
#define scenario4 CYAN                                \
"\nGiven s ← create_sphere()\n"                       \
"When n ← sphere_normal_at(s, point(√3/3, √3/3, √3/3))\n"    \
"Then n = vector(√3/3, √3/3, √3/3)\n"

Test(surface_normals, sphere_normal_at_nonaxial_point, .description = scenario4) {
	const t_tuple	_p1 = {(sqrt(3)/3), (sqrt(3)/3), (sqrt(3)/3), POINT};
	t_sphere		s = create_sphere();
	t_tuple			normal;

	normal = sphere_normal_at(&s, _p1);
	cr_expect_tuples_eq(normal, (t_tuple){sqrt(3)/3, sqrt(3)/3, sqrt(3)/3, VECTOR});
}

// Scenario : The normal is a normalized vector
#define scenario5 CYAN                                   \
"\nGiven s ← sphere()\n"                                 \
"When n ← sphere_normal_at(s, point(√3/3, √3/3, √3/3))\n"       \
"Then n = normalize(n)" RESET

Test(surface_normals, the_normal_is_normalized, .description = scenario5) {
	const t_tuple	_p1 = {(sqrt(3)/3), (sqrt(3)/3), (sqrt(3)/3), POINT};
	t_sphere		s = create_sphere();
	t_tuple			actual_normal;
	t_tuple			expected_normal;

	actual_normal = sphere_normal_at(&s, _p1);
	expected_normal = normalize(actual_normal);
	cr_expect_tuples_eq(actual_normal, expected_normal);
}

// Scenario : Computing the normal on a translated sphere
#define scenario6 CYAN "\n"\
					"Given s ← sphere()\n" \
					"And set_transform(s, translation(0, 1, 0))\n"  \
					"When n ← sphere_normal_at(s, point(0, 1.70711, -0.70711))\n"  \
					"Then n = vector(0, 0.70711, -0.70711)"RESET

Test(surface_normals, normal_on_a_translated_sphere, .description = scenario6) {
	t_sphere		s;
	t_tuple			actual_normal;
	const t_tuple	expected_normal = {0, 0.70711, -0.70711, VECTOR};
	const t_tuple 	p = {0, 1.707107, -0.707107, POINT};
	t_matrix 		transforming_matrix = create_translation_matrix((t_tuple) {0, 1, 0, POINT});

 	s = create_sphere();
	set_transform(&s, transforming_matrix);
	actual_normal = sphere_normal_at(&s, p);
	cr_expect_tuples_eq(actual_normal, expected_normal);
}

// Scenario : Computing the normal on a transformed sphere
#define scenario7 CYAN "\n" \
					"Given s ← sphere()\n"                               \
					"And t ← scaling(1, 0.5, 1) * rotation_z(π/5)\n"     \
					"And set_transform(s, t)\n"                          \
					"When n ← sphere_normal_at(s, point(0, √2/2, -√2/2))\n"     \
					"Then n = vector(0, 0.97014, -0.24254)\n" RESET

#define SQRT_OF_2 	1.41421

Test(surface_normals, normal_on_a_transformed_sphere, .description = scenario7) {
	t_sphere		s;
	t_tuple			actual_normal;
	const t_matrix	t = mult_matrices(create_scaling_matrix(1, 0.5, 1), create_z_rotation_matrix(M_PI/5));
	const t_tuple	p = {0, (SQRT_OF_2/2), (-SQRT_OF_2/2), POINT};
	const t_tuple	expected_normal = {0, 0.97014, -0.24254, VECTOR};

 	s = create_sphere();
	set_transform(&s, t);
	actual_normal = sphere_normal_at(&s, p);
	cr_expect_tuples_eq(actual_normal, expected_normal);
}
