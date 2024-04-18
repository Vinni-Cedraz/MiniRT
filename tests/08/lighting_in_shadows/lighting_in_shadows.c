#include "../../tester.h"

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
		.point = {0, 0, 0, POINT},
		.eye_vec = {0, 0, -1, VECTOR},
		.normal_vec = {0, 0, -1, VECTOR},
		.light = {
			.position = {0, 0, -10, POINT},
			.intensity = {1, 1, 1, COLOR},
		},
		.in_shadow = TRUE,
	};

	res = calculate_lighting(&lighting);
	print_tuple(res);
	cr_assert(tuples_eq(res, (t_tuple){0.1, 0.1, 0.1, COLOR}));
}

//Scenario: There is no shadow when nothing is collinear with point and light
#define scenario2 CYAN \
"Given w ← default_world()\n"                      \
"And p ← point(0, 10, 0)\n"                        \
"Then is_shadowed(w, p) is false"RESET
Test(lighting, no_shadow, .description = scenario2) {
	t_world w = default_world();
	t_tuple p = {0, 10, 0, POINT};

	cr_expect_eq(is_shadowed(&w, p), FALSE);
}

//Scenario: The shadow when an object is between the point and the light
#define scenario3 CYAN \
"Given w ← default_world()\n"                      \
"And p ← point(10, -10, 10)\n"                     \
"Then is_shadowed(w, p) is true"RESET

Test(lighting, shadow, .description = scenario3) {
	t_world w = default_world();
	t_tuple p = {10, -10, 10, POINT};

	cr_expect_eq(is_shadowed(&w, p), TRUE);
}

// Scenario: There is no shadow when an object is behind the light
#define scenario4 CYAN \
"Given w ← default_world()\n"                     \
"And p ← point(-20, 20, -20)\n"                   \
"Then is_shadowed(w, p) is false"RESET

Test(lighting, behind_light, .description = scenario4) {
	t_world w = default_world();
	t_tuple p = {-20, 20, -20, POINT};

	cr_expect_eq(is_shadowed(&w, p), FALSE);
}

// Scenario: There is no shadow when an object is behind the point
#define scenario5 CYAN \
"Given w ← default_world()\n"                   \
"And p ← point(-2, 2, -2)\n"                    \
"Then is_shadowed(w, p) is false"RESET
Test(lighting, behind_point, .description = scenario5) {
	t_world w = default_world();
	t_tuple p = {-2, 2, -2, POINT};

	cr_expect_eq(is_shadowed(&w, p), FALSE);
}
