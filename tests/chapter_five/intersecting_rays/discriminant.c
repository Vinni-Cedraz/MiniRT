#include "tester.h"

// Scenario: calculating the discriminant when there is no intersection
#define scenario6 CYAN \
			"\nGiven ray.origin(0, 2, -5)\n" \
			"And ray.direction(0, 0, 1)\n" \
			"And sphere <- sphere()\n" \
			"And point distance_sphere_to_ray <- subtract_vecs(ray.origin - sphere.origin)\n" \
			"When discriminant ← discriminant(ray, distance_sphere_to_ray)\n" \
			"Then discriminant should be a negative value" RESET

// Copilot, you should calculate the discriminant, take a look at scenario6 description!
Test(discriminant, negative_discriminant, .description = scenario6) {
	const t_ray ray = create_ray((t_tuple){0, 2, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	t_tuple distance_sphere_to_ray;

	subtract_tuples(ray.origin, s.origin, distance_sphere_to_ray);
	if (discriminant(distance_sphere_to_ray, ray) >= 0)
		printf(RED"discriminant: %f\n"RESET, discriminant(distance_sphere_to_ray, ray));
	cr_expect_eq(discriminant(distance_sphere_to_ray, ray) < 0, TRUE);
}
