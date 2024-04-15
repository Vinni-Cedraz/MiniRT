#include "../../tester.h"

#define SQRT_14 3.7416573867739413

// "You normalize a vector by dividing each of its components by its magnitude"

t_tuple res;
const t_tuple vecs[] = 	   {{4, 0, 0, VECTOR}, {1, 2, 3, VECTOR}};
const t_tuple expected[] = {{1, 0, 0, VECTOR}, {1 / SQRT_14, 2 / SQRT_14, 3 / SQRT_14, VECTOR}};

Test(normalization, normalizing_vector_4_0_0) {
    const t_tuple res = normalize(vecs[0]);
    cr_expect_tuples_eq(res, expected[0]);
}

Test(normalization, normalizing_vector_1_2_3) {
    const t_tuple res = normalize(vecs[1]);
	cr_expect_tuples_eq(res, expected[1]);
}

Test(normalization, magnitude_of_normalized_vector_1_2_3) {
    const t_tuple res = normalize(vecs[1]);
    cr_expect_eq(doubles_eq(magnitude(res), 1), TRUE);
}

Test(normalization, normalization_of_point_should_fail) {
	const t_tuple res = normalize((t_tuple){1, 2, 3, POINT});
	cr_expect_eq(-42, res.w);
}
