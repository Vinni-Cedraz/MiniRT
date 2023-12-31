#include "tester.h"
// Scenario : The transformation matrix for the default orientation
#define scenario1 CYAN \
"Given from ← point(0, 0, 0) \n" \
"And to ← point(0, 0, -1) \n" \
"And up ← vector(0, 1, 0) \n" \
"When t ← view_transform(from, forward, up) \n" \
"Then t = identity_matrix RESET\n"

Test(view_transformation, default_orientation, .description = scenario1) {
	t_tuple from = {0, 0, 0, POINT};
	t_tuple to = {0, 0, -1, POINT};
	t_tuple up = {0, 1, 0, VECTOR};
	t_tuple forward;
	t_matrix t;

	subtract_tuples(to, from, forward);
	normalize(forward, forward);
	normalize(up, up);
	t = view_transform(from, forward, up);
	cr_expect_matrices_eq(t, create_identity_matrix());
}

// Scenario : A view transformation matrix looking in positive z direction
#define scenario2 CYAN \
"Given from ← point(0, 0, 0)\n"           \
"And to ← point(0, 0, 1)\n"               \
"And up ← vector(0, 1, 0)\n"              \
"When t ← view_transform(from, forward, up)\n" \
"Then t = scaling(-1, 1, -1)\n"RESET
Test(view_transformation, positive_z_direction, .description = scenario2) {
	t_tuple from = {0, 0, 0, POINT};
	t_tuple to = {0, 0, 1, POINT};
	t_tuple up = {0, 1, 0, VECTOR};
	t_tuple forward;
	t_matrix t;

	subtract_tuples(to, from, forward);
	normalize(forward, forward);
	normalize(up, up);
	t = view_transform(from, forward, up);
	cr_expect_matrices_eq(t, create_scaling_matrix(-1, 1, -1));
}

// Scenario : The view transformation moves the world
#define scenario3 CYAN \
"Given from ← point(0, 0, 8)\n"                \
"And to ← point(0, 0, 0)\n"                    \
"And up ← vector(0, 1, 0)\n"                   \
"When t ← view_transform(from, forward, up)\n"      \
"Then t = translation(0, 0, -8)\n"RESET
Test(view_transformation, moves_the_world, .description = scenario3) {
	t_tuple from = {0, 0, 8, POINT};
	t_tuple to = {0, 0, 0, POINT};
	t_tuple up = {0, 1, 0, VECTOR};
	t_tuple forward;
	t_matrix t;

	subtract_tuples(to, from, forward);
	normalize(forward, forward);
	normalize(up, up);
	t = view_transform(from, forward, up);
	cr_expect_matrices_eq(t, create_translation_matrix((t_tuple){0, 0, -8, POINT}));
}

// Scenario : An arbitrary view transformation
#define scenario4 CYAN \
"Given from ← point(1, 3, 2)\n"                              \
"And to ← point(4, -2, 8)\n"                                 \
"And up ← vector(1, 1, 0)\n"                                 \
"When t ← view_transform(from, forward, up)\n"                    \
"Then t is the following 4x4 matrix:\n"                      \
"| -0.50709 | 0.50709 | 0.67612  | -2.36643 |\n"             \
"| 0.76772  | 0.60609 | 0.12122  | -2.82843 |\n"			 \
"| -0.35857 | 0.59761 | -0.71714 | 0.00000  |\n"    		 \
"| 0.00000  | 0.00000 | 0.00000  | 1.00000  |\n"RESET
Test(view_transformation, arbitrary_transformation, .description = scenario4) {
	t_tuple 	from = {1, 3, 2, POINT};
	t_tuple 	to = {4, -2, 8, POINT};
	t_tuple 	up = {1, 1, 0, VECTOR};
	const t_matrix	expected_t = {
		-0.50709, 0.50709, 0.67612, -2.36643,
		0.76772, 0.60609, 0.12122, -2.82843,
		-0.35857, 0.59761, -0.71714, 0.00000,
		0, 0, 0, 1
	};
	t_tuple forward;
	t_matrix t;

	subtract_tuples(to, from, forward);
	normalize(forward, forward);
	normalize(up, up);
	t = view_transform(from, forward, up);
	cr_expect_matrices_eq(t, expected_t);
}
