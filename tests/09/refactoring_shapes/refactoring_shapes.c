#include "tester.h"

// Scenario : Computing the normal on a transformed shape
#define scenario1 CYAN \
"Given s ← test_shape()\n" \
"And m ← scaling(1, 0.5, 1) * rotation_z(π/5)\n" \
"When set_transform(s, m)\n" \
"And n ← normal_at(s, point(0, √2/2, -√2/2))\n" \
"Then n = vector(0, 0.97014, -0.24254)\n" RESET

Test(refactoring_shapes, normal_after_transformation, .description = scenario1) {
	t_sphere s1 = create_sphere();
	t_matrix scaling_matrix = create_scaling_matrix(1, 0.5, 1);
	t_matrix rotation_z_matrix = create_z_rotation_matrix(M_PI/5);
	const t_matrix final_transformation = chain_transformations(
			(t_matrix*[]){&rotation_z_matrix, &scaling_matrix, NULL}
	);
	const t_normal_at_function normal_at[3] = {
		sphere_normal_at, plane_normal_at, cylinder_normal_at
	};
	t_tuple sphere_normalv;

	set_transform((t_shape *)&s1, final_transformation);
	normal_at[s1.type]((t_shape*)&s1, (t_tuple){0, sqrt(2)/2, -sqrt(2)/2, POINT}, sphere_normalv);
	print_tuple(sphere_normalv);
	cr_expect_tuples_eq(sphere_normalv, (t_tuple){0, 0.97014, -0.24254, VECTOR});
}
