#include "tester.h"

#define SQRT_OF_14 3.7416573867739413

const t_tuple vectors[] = {
		{1, 2, 3, VECTOR},
		{1, -2, -3, VECTOR},
		{1, 0, 0, VECTOR},
		{0, 1, 0, VECTOR},
		{0, 0, 1, VECTOR},
		{0, 0, 1, POINT}
};

const double expected_results[] = {
		SQRT_OF_14,
		SQRT_OF_14,
		1,
		1,
		1,
		-1
};

Test(magnitude, magnitude_of_positive_vector) {
	cr_expect_eq(magnitude(vectors[0]), expected_results[0]);
}

Test(magnitude, magnitude_of_negative_vector) {
	cr_expect_eq(magnitude(vectors[1]), expected_results[1]);
}

Test(magnitude, magnitude_of_unit_vector1) {
	cr_expect_eq(magnitude(vectors[2]), expected_results[2]);
}

Test(magnitude, magnitude_of_unit_vector2) {
	cr_expect_eq(magnitude(vectors[3]), expected_results[3]);
}

Test(magnitude, magnitude_of_unit_vector3) {
	cr_expect_eq(magnitude(vectors[4]), expected_results[4]);
}

Test(magnitude, magnitude_of_a_point_should_be_always_negative_one) {
	cr_expect_eq(magnitude(vectors[5]), expected_results[5]);
}
