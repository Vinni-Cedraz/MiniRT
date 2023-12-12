#include "tester.h"

// Scenario: Lighting with the surface in shadow
#define scenario1 CYAN \
"Given m ← material()\n"                                                     		   \
"And position ← point(0, 0, 0)\n"                                                      \
"Given eyev ← vector(0, 0, -1)\n"                                                      \
"And normalv ← vector(0, 0, -1)\n"                                                     \
"And light ← point_light(point(0, 0, -10), color(1, 1, 1))\n"                          \
"And in_shadow ← true\n"                                                      		   \
"When result ← calculate_lighting(m, light, position, eyev, normalv, in_shadow)\n"               \
"Then result = color(0.1, 0.1, 0.1)"RESET

Test(lighting, surface_in_shadow, .description = scenario1) {

	t_tuple res;
	t_lighting lighting = {
		.material = create_material(),
		.position = {0, 0, 0, POINT},
		.eye_vec = {0, 0, -1, VECTOR},
		.normal_vec = {0, 0, -1, VECTOR},
		.light = {
			.position = {0, 0, -10, POINT},
			.intensity = {1, 1, 1, COLOR},
		},
		.in_shadow = TRUE,
	};

	calculate_lighting(&lighting, res);
	printf("res =>");
	print_tuple(res);
	cr_assert(tuples_eq(res, (t_tuple){0.1, 0.1, 0.1, COLOR}));
}
