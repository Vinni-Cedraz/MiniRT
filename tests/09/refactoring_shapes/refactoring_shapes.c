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

Test(refactoring_shapes, ray_transformed_on_scaled_shape, .description = scenario2) {
	t_sphere s = create_sphere();
	t_matrix m = create_scaling_matrix(2, 2, 2);
	const t_ray expected_transformed_ray = {
		.origin = {0, 0, -2.5, POINT},
		.direction = {0, 0, 0.5, VECTOR},
	};

	set_transform((t_shape *)&s, m);
	create_intersection(&s, r);
	cr_expect_tuples_eq(s.r.origin, expected_transformed_ray.origin);
	cr_expect_tuples_eq(s.r.direction, expected_transformed_ray.direction);
}

// Scenario: Intersecting a scaled shape with a ray
#define scenario3 CYAN \
			"\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))" \
			"When set_transform(s, translation(5, 0, 0))\n" \
			"And xs ← intersect(s, r)\n" \
			"Then transformed ray origin = point(-5, 0, -5)\n" \
			"And transformed ray direction = vector(0, 0, 1)"RESET

Test(refactoring_shapes, ray_transformed_on_translated_shape, .description = scenario3) {
	t_sphere s = create_sphere();
	t_matrix m = create_translation_matrix((t_tuple){5, 0, 0, POINT});
	const t_ray expected_transformed_ray = {
		.origin = {-5, 0, -5, POINT},
		.direction = {0, 0, 1, VECTOR},
	};

	set_transform((t_shape *)&s, m);
	create_intersection(&s, r);
	cr_expect_tuples_eq(s.r.origin, expected_transformed_ray.origin);
	cr_expect_tuples_eq(s.r.direction, expected_transformed_ray.direction);
}

//Scenario: Computing the normal on a translated shape
#define scenario4 CYAN \
"\nGiven s ← test_shape()" \
"When set_transform(s, translation(0, 1, 0))\n" \
"And n ← normal_at(s, point(0, 1.70711, -0.70711))\n" \
"Then n = vector(0, 0.70711, -0.70711)"RESET

Test(refactoring_shapes, normal_on_translated_shape, .description = scenario4) {
	t_sphere s = create_sphere();
	t_tuple normal;
	t_tuple expected_normal = {0, 0.70711, -0.70711, VECTOR};

	set_transform((t_shape*)&s, create_translation_matrix((t_tuple){0, 1, 0, POINT}));
	sphere_normal_at((t_shape *)&s, (t_tuple){0, 1.70711, -0.70711, POINT}, normal);
	cr_expect_tuples_eq(normal, expected_normal);
}
