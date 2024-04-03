#include "../../tester.h"

// Scenario: calculating the discriminant when there is no intersection
#define scenario1 CYAN \
			"\nGiven ray.origin(0, 2, -5)\n" \
			"And ray.direction(0, 0, 1)\n" \
			"And sphere <- sphere()\n" \
			"And point distance_sphere_to_ray <- subtract_vecs(ray.origin - sphere.origin)\n" \
			"When discriminant ← discriminant(ray, distance_sphere_to_ray)\n" \
			"Then discriminant should be a negative value" RESET

Test(discriminant, negative_discriminant_no_intersections, .description = scenario1) {
	const t_ray ray = create_ray((t_tuple){0, 2, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	t_tuple distance_sphere_to_ray = subtract_tuples(ray.origin, s.origin);
	if (discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}) >= 0)
		printf(RED"discriminant: %f\n"RESET, discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}));
	cr_expect_eq(discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}) < 0, TRUE);
}

// Scenario: calculating the discriminant when there are two intersections:
#define scenario2 CYAN \
			"\nGiven ray.origin(0, 2, -5)\n" \
			"And ray.direction(0, 0, 1)\n" \
			"And sphere <- sphere()\n" \
			"And point distance_sphere_to_ray <- subtract_vecs(ray.origin - sphere.origin)\n" \
			"When discriminant ← discriminant(ray, distance_sphere_to_ray)\n" \
			"Then discriminant should be a negative value" RESET

Test(discriminant, positive_discriminant_two_intersections, .description = scenario2) {
	const t_ray ray = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	t_tuple distance_sphere_to_ray;

	distance_sphere_to_ray = subtract_tuples(ray.origin, s.origin);
	if (discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}) < 0)
		printf(RED"discriminant: %f\n"RESET, discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}));
	cr_expect_eq(discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}) >= 0, TRUE);
}

// Scenario: calculating the discriminant when the ray is inside the sphere
#define scenario3 CYAN \
			"\nGiven ray.origin(0, 0, 0)\n" \
			"And ray.direction(0, 0, 1)\n" \
			"And sphere <- sphere()\n" \
			"And point distance_sphere_to_ray <- subtract_vecs(ray.origin - sphere.origin)\n" \
			"When discriminant ← discriminant(ray, distance_sphere_to_ray)\n" \
			"Then discriminant should be a positive value" RESET

Test(discriminant, inside_sphere_positive_discriminant, .description = scenario3) {
	const t_ray ray = create_ray((t_tuple){0, 0, 0, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	t_tuple distance_sphere_to_ray;

	distance_sphere_to_ray = subtract_tuples(ray.origin, s.origin);
	if (discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}) < 0)
		printf(RED"discriminant: %f\n"RESET, discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}));
	cr_expect_eq(discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}) >= 0, TRUE);
}

// Scenario: calculatin the discriminant when there is a single intersection (at the tangent of the sphere)

#define scenario4 CYAN \
	"\nGiven ray.origin(0, 1, -5)\n" \
	"And ray.direction(0, 0, 1)\n" \
	"And sphere <- sphere()\n" \
	"And point distance_sphere_to_ray <- subtract_vecs(ray.origin - sphere.origin)\n" \
	"When discriminant ← discriminant(ray, distance_sphere_to_ray)\n" \
	"The discriminant should be a positive value" RESET

Test(discriminant, single_intersection_discriminant_is_zero, .description = scenario4) {
	const t_ray ray = create_ray((t_tuple){0, 1, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	t_tuple distance_sphere_to_ray;
	
	distance_sphere_to_ray = subtract_tuples(ray.origin, s.origin);
	if (discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}) < 0)
		printf(RED"discriminant: %f\n"RESET, discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}));
	cr_expect_eq(discriminant(distance_sphere_to_ray, ray, &(t_baskara){0}) >= 0, TRUE);
}
