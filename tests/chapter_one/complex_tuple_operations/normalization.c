#include "tester.h"

#define SQRT_14 3.7416573867739413

// "You normalize a vector by dividing each of its components by its magnitude"

t_tuple res;
const t_tuple vecs[] = 	   {{4, 0, 0, VECTOR}, {1, 2, 3, VECTOR}};
const t_tuple expected[] = {{1, 0, 0, VECTOR}, {1 / SQRT_14, 2 / SQRT_14, 3 / SQRT_14, VECTOR}};

Test(normalization, normalizing_vector_4_0_0) {
    normalize(vecs[0], res);
    cr_expect_arr_eq(res, expected[0], sizeof(t_tuple));
}

Test(normalization, normalizing_vector_1_2_3) {
    normalize(vecs[1], res);
	cr_expect_tuple_eq(res, expected[1]);
}

Test(normalization, magnitude_of_normalized_vector_1_2_3) {
    normalize(vecs[1], res);
    cr_expect_eq(floats_eq(magnitude(res), 1), TRUE);
}

Test(normalization, normalization_of_zero_magnitude_vector_should_fail) {
	cr_expect_eq(normalize((t_tuple){0, 0, 0, VECTOR}, res), -1);
}

Test(normalization, normalization_of_point_should_fail) {
	cr_expect_eq(normalize((t_tuple){1, 2, 3, POINT}, res), -1);
}
