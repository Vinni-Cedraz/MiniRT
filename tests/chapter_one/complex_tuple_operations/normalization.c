#include "tester.h"

#define suite_name normalization
#define SQRT_14 3.7416573867739413

TestSuite(suite_name);
// "You normalize a vector by dividing each of its components by its magnitude"

t_tuple res;
const t_tuple vecs[] = 	   {{4, 0, 0, VECTOR}, {1, 2, 3, VECTOR}};
const t_tuple expected[] = {{1, 0, 0, VECTOR}, {1 / SQRT_14, 2 / SQRT_14, 3 / SQRT_14, VECTOR}};

Test(suite_name, normalizing_vector_4_0_0) {
    normalize(vecs[0], res);
    cr_expect_arr_eq(res, expected[0], sizeof(t_tuple));
}

Test(suite_name, normalizing_vector_1_2_3) {
    normalize(vecs[1], res);
	t_bool is_equal = cr_expect_tuple_eq(res, expected[1]);
	cr_expect_eq(is_equal, TRUE);
}

Test(suite_name, magnitude_of_normalized_vector_1_2_3) {
    normalize(vecs[1], res);
    cr_expect_eq(compare_floats(magnitude(res), 1), TRUE);
}

Test(suite_name, normalization_of_zero_magnitude_vector_should_fail) {
	cr_expect_eq(normalize((t_tuple){0, 0, 0, VECTOR}, res), -1);
}

Test(suite_name, normalization_of_point_should_fail) {
	cr_expect_eq(normalize((t_tuple){1, 2, 3, POINT}, res), -1);
}
