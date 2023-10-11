#include "tester.h"

// Scenario : Rotating a point around the x axis
#define scenario2 CYAN "\n" \
				"Given p ← point(0, 1, 0)\n" \
				"And half_quarter ← create_x_rotation_matrix(π / 4)\n"              \
				"And full_quarter ← create_x_rotation_matrix(π / 2)\n"              \
				"Then half_quarter * p = point(0, 0.707107, 0.707107)\n"                    \
				"And full_quarter * p = point(0, 0, 1)" RESET

Test(rotation, rotating_around_x_axis, .description = scenario2) {
	t_tuple res;
	t_tuple p = {0, 1, 0, POINT};
	const t_matrix half_quarter = create_x_rotation_matrix(M_PI / 4);
	const t_matrix full_quarter = create_x_rotation_matrix(M_PI / 2);
	const t_tuple expected1 = {0, 0.707107, 0.707107, POINT};
	const t_tuple expected2 = {0, 0, 1, POINT};
	multiply_tuple_by_matrix(p, half_quarter, res);
	cr_expect_tuple_eq(res, expected1);
	multiply_tuple_by_matrix(p, full_quarter, res);
	cr_expect_tuple_eq(res, expected2);
}

//Scenario : The inverse of an x-rotation rotates in the opposite direction
#define scenario3 "CYAN\n"                                           \
				   "Given p ← point(0, 1, 0)\n"                      \
				  "And half_quarter ← rotation_x(π / 4)\n"           \
				  "And inv ← inverse(half_quarter)\n"                \
				  "Then inv * p = point(0, 0.707107, -0.707107)"RESET

Test(rotation, the_inverse_of_the_rotation_matrix_rotates_in_the_opposite_direction, .description = scenario3) {
	t_tuple res;
	t_tuple p = {0, 1, 0, POINT};
	const t_matrix half_quarter = create_x_rotation_matrix(M_PI / 4);
	const t_tuple expected = {0, 0.70710, -0.70710, POINT};
	const t_matrix inverse_rotation = invert_matrix(half_quarter);
	multiply_tuple_by_matrix(p, inverse_rotation, res);
	cr_expect_tuple_eq(res, expected);
}
