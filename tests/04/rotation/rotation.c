#include "tester.h"

t_tuple 		res;
const t_tuple	p = {0, 1, 0, POINT};

// Scenario : Rotating a point around the x axis
#define scenario2 CYAN "\n" \
				"Given p ← point(0, 1, 0)\n" \
				"And half_quarter ← create_x_rotation_matrix(π / 4)\n"              \
				"And full_quarter ← create_x_rotation_matrix(π / 2)\n"              \
				"Then half_quarter * p = point(0, 0.707107, 0.707107)\n"                    \
				"And full_quarter * p = point(0, 0, 1)" RESET

Test(rotation, rotating_around_x_axis, .description = scenario2) {
	const t_matrix half_quarter = create_x_rotation_matrix(M_PI / 4);
	const t_matrix full_quarter = create_x_rotation_matrix(M_PI / 2);
	const t_tuple expected1 = {0, 0.707107, 0.707107, POINT};
	const t_tuple expected2 = {0, 0, 1, POINT};
	multiply_tuple_by_matrix(p, half_quarter, res);
	cr_expect_tuples_eq(res, expected1);
	multiply_tuple_by_matrix(p, full_quarter, res);
	cr_expect_tuples_eq(res, expected2);
}

//Scenario : The inverse of an x-rotation rotates in the opposite direction
#define scenario3 "CYAN\n"                                           \
				   "Given p ← point(0, 1, 0)\n"                      \
				  "And half_quarter ← rotation_x(π / 4)\n"           \
				  "And inv ← inverse(half_quarter)\n"                \
				  "Then inv * p = point(0, 0.707107, -0.707107)"RESET

Test(rotation, the_inverse_of_the_rotation_matrix_rotates_in_the_opposite_direction, .description = scenario3) {
	const t_matrix half_quarter = create_x_rotation_matrix(M_PI/4);
	const t_matrix inverse_rotation = invert_matrix(half_quarter);
	const t_tuple expected = {0, (sqrt(2)/2), -(sqrt(2)/2), POINT};
	multiply_tuple_by_matrix(p, inverse_rotation, res);
	print_tuple(res);
	cr_expect_tuples_eq(res, expected);
}

// Scenario : Rotating a point around the y axis
#define scenario3 "CYAN\n"                                          \
				  "Given p ← point(0, 0, 1)\n"                      \
				  "And half_quarter ← rotation_y(π / 4)\n"          \
				  "And full_quarter ← rotation_y(π / 2)\n"		    \
				  "Then half_quarter * p = point(0.707107, 0, 0.707107)\n"  \
				  "And full_quarter * p = point(1, 0, 0)" RESET

Test(rotation, rotating_around_y_axis, .description = scenario3) {
	const t_tuple	p = {0, 0, 1, POINT};
	const t_matrix	half_quarter = create_y_rotation_matrix(M_PI / 4);
	const t_matrix	full_quarter = create_y_rotation_matrix(M_PI / 2);
	const t_tuple	expected1 = {0.707107, 0, 0.707107, POINT};
	const t_tuple	expected2 = {1, 0, 0, POINT};
	multiply_tuple_by_matrix(p, half_quarter, res);
	cr_expect_tuples_eq(expected1, res);
	multiply_tuple_by_matrix(p, full_quarter, res);
	cr_expect_tuples_eq(expected2, res);
}

// Scenario : Rotating a point around the z axis
#define scenario4 "CYAN\n"                                          \
				  "Given p ← point(0, 1, 0)And half_quarter ← rotation_z(π / 4)\n"    \
				  "And full_quarter ← rotation_z(π / 2)\n"                            \
				  "Then half_quarter * p = point(-0.707107, 0.707107, 0)\n"                   \
				  "And full_quarter * p = point(-1, 0, 0)" RESET

Test(rotation, rotating_around_z_axis, .description = scenario4) {
	const t_matrix	half_quarter = create_z_rotation_matrix(M_PI / 4);
	const t_matrix	full_quarter = create_z_rotation_matrix(M_PI / 2);
	const t_tuple	expected1 = {-0.707107, 0.707107, 0, POINT};
	const t_tuple	expected2 = {-1, 0, 0, POINT};
	t_tuple 		res;
	
	multiply_tuple_by_matrix(p, half_quarter, res);
	cr_expect_tuples_eq(expected1, res);
	multiply_tuple_by_matrix(p, full_quarter, res);
	cr_expect_tuples_eq(expected2, res);
}
