#include "../../tester.h"

// Scenario : Computing the normal on a transformed shape
#define scenario1 CYAN \
"Given s ← test_shape()\n" \
"And m ← scaling(1, 0.5, 1) * rotation_z(π/5)\n" \
"When set_transform(s, m)\n" \
"And n ← normal_at(s, point(0, √2/2, -√2/2))\n" \
"Then n = vector(0, 0.97014, -0.24254)\n" RESET

Test(refactoring_shapes, normal_after_transformation, .description = scenario1) {
	t_shape s1 = create_sphere();
	t_matrix scaling_matrix = create_scaling_matrix(1, 0.5, 1);
	t_matrix rotation_z_matrix = create_z_rotation_matrix(M_PI/5);
	const t_matrix final_transformation = chain_transformations(
			(t_matrix[]){rotation_z_matrix, scaling_matrix, create_identity_matrix()}
	);
	t_tuple sphere_normalv;

	set_transform((t_shape *)&s1, final_transformation);
	sphere_normalv = s1.normal_at((t_shape*)&s1, create_point(0, sqrt(2)/2, -sqrt(2)/2));
	cr_expect_tuples_eq(sphere_normalv, (t_tuple){0, 0.97014, -0.24254, VECTOR});
}

// Scenario: Intersecting a scaled shape with a ray
#define scenario2 CYAN \
			"\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))" \
			"When set_transform(s, scaling(2, 2, 2))\n" \
			"And xs ← intersect(s, r)\n" \
			"Then transformed ray origin = point(0, 0, -2.5)\n" \
			"And transformed ray direction = vector(0, 0, 0.5)"RESET

const t_ray r = {
		.origin = {0, 0, -5, POINT},
		.direction = {0, 0, 1, VECTOR},
};

//Scenario: Computing the normal on a translated shape
#define scenario4 CYAN \
"\nGiven s ← test_shape()" \
"When set_transform(s, translation(0, 1, 0))\n" \
"And n ← normal_at(s, point(0, 1.70711, -0.70711))\n" \
"Then n = vector(0, 0.70711, -0.70711)"RESET

Test(refactoring_shapes, normal_on_translated_shape, .description = scenario4) {
	t_shape s = create_sphere();
	t_tuple normal;
	t_tuple expected_normal = {0, 0.70711, -0.70711, VECTOR};

	set_transform((t_shape*)&s, create_translation_matrix((t_tuple){0, 1, 0, POINT}));
	normal = sphere_normal_at((t_shape *)&s, (t_tuple){0, 1.70711, -0.70711, POINT});
	cr_expect_tuples_eq(normal, expected_normal);
}
