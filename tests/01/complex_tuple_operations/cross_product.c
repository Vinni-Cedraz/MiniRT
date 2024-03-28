#include "../../tester.h"

// the resulting vector is perpendicular to both inputs

#define scenario1 CYAN"\nGiven a ← vector(1, 2, 3)\n"              \
					    "And b ← vector(2, 3, 4)\n"                \
					    "And cross(a, b, result)\n"                \
						"Then result == vector(-1, 2, -1)"RESET

#define scenario2 CYAN"\nGiven a ← vector(1, 2, 3)\n"               \
					    "And b ← vector(2, 3, 4)\n"                 \
					    "And cross(b, a, result)\n"                 \
						"Then result == vector(1, -2, 1)"RESET

#define scenario3 CYAN"\nGiven a ← point(1, 2, 3)\n"                \
					    "And b ← point(2, 3, 4)\n"                  \
					    "And res = cross(b, a)\n"		            \
						"Then res.w = -42"RESET

const t_tuple a = {1, 2, 3, VECTOR};
const t_tuple b = {2, 3, 4, VECTOR};

Test(cross_product, cross_product_of_a_b, .description = scenario1) {
	const t_tuple expected = {-1, 2, -1, VECTOR};
	const t_tuple result = cross(a, b);
	cr_expect_eq(result.w, VECTOR, RED"cross product of two vectors should be a vector"RESET);
	cr_expect_tuples_eq(expected, result);
}

Test(cross_product, cross_product_of_b_a, .description = scenario2) {
	const t_tuple expected = {1, -2, 1, VECTOR};
	const t_tuple result = cross(b, a);
	cr_expect_eq(result.w, VECTOR, RED"cross product of two vectors should be a vector"RESET);
	cr_expect_tuples_eq(expected, result);
}

Test(cross_product, cross_product_of_points_should_fail, .description = scenario3) {
	const t_tuple a = {1, 2, 3, POINT};
	const t_tuple b = {2, 3, 4, POINT};
	const t_tuple err = cross(a, b);
	cr_assert_eq(err.w, -42, RED"cross product of two points should fail with -42"RESET);
}
