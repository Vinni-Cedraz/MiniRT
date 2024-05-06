#include "../../tester.h"
// Scenario: There is no shadow when nothing is collinear with point and light
#define scenario1 CYAN \
		    "\nGiven w ← default_world()" 						 \
			"And p ← point(0, 10, 0)\n"                          \
			"Then is_shadowed(w, p) is false"RESET

Test(testing_for_shadows, there_is_no_shadow_when_nothing_is_collinear, .description = scenario1) {
	t_world w = default_world();
	t_tuple p = {0, 10, 0, POINT};

	cr_expect_eq(is_shadowed(&w, p), false);
}

// Scenario: The shadow when an object is between the point and the light
#define scenario2 CYAN \
	"\nGiven w ← default_world()" \
	"And p ← point(10, -10, 10)\n"    \
	"Then is_shadowed(w, p) is true"RESET

Test(testing_for_shadows, when_object_is_between_the_point_and_light, .description = scenario2) {
	t_world w = default_world();
	t_tuple p = {10, -10, 10, POINT};

	cr_expect_eq(is_shadowed(&w, p), true);
}

// Scenario: There is no shadow when an object is behind the light
#define scenario3 CYAN \
"\nGiven w ← default_world()" \
"And p ← point(-20, 20, -20)\n" \
"Then is_shadowed(w, p) is false"RESET

Test(testing_for_shadows, no_shadow_when_object_behind_light, .description = scenario3) {
	t_world w = default_world();
	t_tuple p = {-20, 20, -20, POINT};

	cr_expect_eq(is_shadowed(&w, p), false);
}

// Scenario: There is no shadow when an object is behind the point
#define scenario4 CYAN \
"\nGiven w ← default_world()" \
"And p ← point(-2, 2, -2)\n"  \
"Then is_shadowed(w, p) is false"RESET

Test(testing_for_shadows, no_shadow_when_object_behind_point, .description = scenario4) {
	t_world w = default_world();
	t_tuple p = {-2, 2, -2, POINT};

	cr_expect_eq(is_shadowed(&w, p), false);
}
