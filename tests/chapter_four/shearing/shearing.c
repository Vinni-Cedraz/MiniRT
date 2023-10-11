#include "tester.h"

// scenario: a struct called t_shearer exists
#define scenario0 CYAN \
	"\nGiven t_shearer shearer = {1, 0, 4, 0, 0, 0}\n" \
	"Then shearer.x_to_y == 1\n" \
	"and shearer.x_to_z == 0\n"  \
	"and shearer.y_to_x == 4\n"  \
	"and shearer.y_to_z == 0\n"  \
	"and shearer.z_to_x == 0\n"  \
	"and shearer.z_to_y == 0" RESET

Test(shearing, t_shearing_exists, .description = scenario0) {
	const t_shearer shearer = {1, 0, 4, 0, 0, 0};
	cr_assert(shearer.x_to_y == 1);
	cr_assert(shearer.x_to_z == 0);
	cr_assert(shearer.y_to_x == 4);
	cr_assert(shearer.y_to_z == 0);
	cr_assert(shearer.z_to_x == 0);
	cr_assert(shearer.z_to_y == 0);
}

// Scenario : A shearing transformation moves x in proportion to y
#define scenario1 CYAN \
						"\nGiven transform ← create_shearing_matrix(1, 0, 0, 0, 0, 0)\n"   \
						"And p ← point(2, 3, 4)\n"  \
						"Then transform * p = point(5, 3, 4)" RESET \

Test(shearing, shear_x_in_proportion_to_y, .description = scenario1) {
	const t_shearer shearer = {1, 0, 0, 0, 0, 0};
	const t_matrix transform = create_shearing_matrix(shearer);
	const t_tuple p = {2, 3, 4, POINT};
	const t_tuple expected = {5, 3, 4, POINT};
	const t_tuple actual;

	multiply_tuple_by_matrix(p, transform, actual);
	cr_expect_tuple_eq(actual, expected);
}

// Scenario : A shearing transformation moves x in proportion to z
#define scenario2 CYAN \
	"Given transform ← create_shearing_matrix(0, 1, 0, 0, 0, 0)\n" \
	"And p ← point(2, 3, 4)\n" \
	"Then transform * p = point(6, 3, 4)" RESET \

Test(shearing, shear_x_in_proportion_to_z, .description = scenario2) {
	const t_shearer shearer = {0, 1, 0, 0, 0, 0};
	const t_matrix	transform = create_shearing_matrix(shearer);
	const t_tuple 	p = {2, 3, 4, POINT};
	const t_tuple 	expected = {6, 3, 4, POINT};
	const t_tuple 	actual;

	multiply_tuple_by_matrix(p, transform, actual);
	cr_expect_tuple_eq(actual, expected);
}

// Scenario : A shearing transformation moves y in proportion to x
#define scenario3 CYAN \
	"Given transform ← create_shearing_matrix(0, 0, 1, 0, 0, 0)\n" \
	"And p ← point(2, 3, 4)\n" \
	"Then transform * p = point(2, 5, 4)" RESET \

Test(shearing, shear_y_in_proportion_to_x, .description = scenario3) {
	const t_shearer shearer = {0, 0, 1, 0, 0, 0};
	const t_matrix	transform = create_shearing_matrix(shearer);
	const t_tuple 	p = {2, 3, 4, POINT};
	const t_tuple 	expected = {2, 5, 4, POINT};
	const t_tuple 	actual;

	multiply_tuple_by_matrix(p, transform, actual);
	cr_expect_tuple_eq(actual, expected);
}

// Scenario : A shearing transformation moves y in proportion to z
#define scenario4 CYAN \
	"Given transform ← create_shearing_matrix(0, 0, 0, 1, 0, 0)\n" \
	"And p ← point(2, 3, 4)\n" \
	"Then transform * p = point(2, 7, 4)" RESET \

Test(shearing, shear_y_in_proportion_to_z, .description = scenario4) {
	const t_shearer shearer = {0, 0, 0, 1, 0, 0};
	const t_matrix	transform = create_shearing_matrix(shearer);
	const t_tuple 	p = {2, 3, 4, POINT};
	const t_tuple 	expected = {2, 7, 4, POINT};
	const t_tuple 	actual;

	multiply_tuple_by_matrix(p, transform, actual);
	cr_expect_tuple_eq(actual, expected);
}

// Scenario : A shearing transformation moves z in proportion to x
#define scenario5 CYAN \
	"Given transform ← create_shearing_matrix(0, 0, 0, 0, 1, 0)\n" \
	"And p ← point(2, 3, 4)\n" \
	"Then transform * p = point(2, 3, 6)" RESET \

Test(shearing, shear_z_in_proportion_to_x, .description = scenario5) {
	const t_shearer shearer = {0, 0, 0, 0, 1, 0};
	const t_matrix	transform = create_shearing_matrix(shearer);
	const t_tuple 	p = {2, 3, 4, POINT};
	const t_tuple 	expected = {2, 3, 6, POINT};
	const t_tuple 	actual;

	multiply_tuple_by_matrix(p, transform, actual);
	cr_expect_tuple_eq(actual, expected);
}

// Scenario : A shearing transformation moves z in proportion to y
#define scenario6 CYAN \
	"Given transform ← create_shearing_matrix(0, 0, 0, 0, 0, 1)\n" \
	"And p ← point(2, 3, 4)\n" \
	"Then transform * p = point(2, 3, 7)" RESET \

Test(shearing, shear_z_in_proportion_to_y, .description = scenario6) {
	const t_shearer shearer = {0, 0, 0, 0, 0, 1};
	const t_matrix	transform = create_shearing_matrix(shearer);
	const t_tuple 	p = {2, 3, 4, POINT};
	const t_tuple 	expected = {2, 3, 7, POINT};
	const t_tuple 	actual;

	multiply_tuple_by_matrix(p, transform, actual);
	cr_expect_tuple_eq(actual, expected);
}
