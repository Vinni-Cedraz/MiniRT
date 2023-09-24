#include "tester.h"

#define suite_name cross_product

#define scenario1 CYAN"\nGiven a ← vector(1, 2, 3)\n"              \
					    "And b ← vector(2, 3, 4)\n"                \
					    "And cross(a, b, result)\n"                \
						"Then result == vector(-1, 2, -1)" RESET

#define scenario2 CYAN"\nGiven a ← vector(1, 2, 3)\n"               \
					    "And b ← vector(2, 3, 4)\n"                 \
					    "And cross(b, a, result)\n"                 \
						"Then result == vector(1, -2, 1)" RESET

#define scenario3 CYAN"\nGiven a ← point(1, 2, 3)\n"                \
					    "And b ← point(2, 3, 4)\n"                  \
					    "Then cross(b, a) == -1\n" RESET            \

const t_tuple a = {1, 2, 3};
const t_tuple b = {2, 3, 4};

Test(suite_name, cross_product_of_a_b, .description = scenario1) {
	const t_tuple expected = {-1, 2, -1};
	t_tuple result;
	cross(a, b, result);
	cr_assert_arr_eq(expected, result, sizeof(t_tuple));
}

Test(suite_name, cross_product_of_b_a, .description = scenario2) {
	const t_tuple expected = {1, -2, 1};
	t_tuple result;
	cross(b, a, result);
	cr_assert_arr_eq(expected, result, sizeof(t_tuple));
}

Test(suite_name, cross_product_of_points_should_fail, .description = scenario3) {
	const t_tuple a = {1, 2, 3, POINT};
	const t_tuple b = {2, 3, 4, POINT};
	int err = cross(a, b, (t_tuple){0});
	cr_assert_eq(err, -1);
}
