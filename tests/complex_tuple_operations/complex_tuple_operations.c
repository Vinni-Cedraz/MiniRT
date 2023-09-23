#include "../tester.h"
#include "../../src/complex_tuple_operations.c"

#define suite_name complex_tuple_operations
#define SQRT_OF_14 3.7416573867739413

const t_tuple vectors[] = {
		{1, 2, 3, VECTOR},
		{1, -2, -3, VECTOR},
		{1, 0, 0, VECTOR},
		{0, 1, 0, VECTOR},
		{0, 0, 1, VECTOR}
};

const float expected_results[] = {
		SQRT_OF_14,
		SQRT_OF_14,
		1,
		1,
		1
};

Test(suite_name, magnitude_of_positive_vector) {
	cr_expect_eq(vector_magnitude(vectors[0]), expected_results[0]);
}

Test(suite_name, magnitude_of_negative_vector) {
	cr_expect_eq(vector_magnitude(vectors[1]), expected_results[1]);
}

Test(suite_name, magnitude_of_unit_vector1) {
	cr_expect_eq(vector_magnitude(vectors[2]), expected_results[2]);
}

Test(suite_name, magnitude_of_unit_vector2) {
	cr_expect_eq(vector_magnitude(vectors[3]), expected_results[3]);
}

Test(suite_name, magnitude_of_unit_vector3) {
	cr_expect_eq(vector_magnitude(vectors[4]), expected_results[4]);
}
