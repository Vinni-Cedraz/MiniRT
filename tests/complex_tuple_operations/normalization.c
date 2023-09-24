// #include "../../src/complex_tuple_operations.c"
#include "tester.h"

#define suite_name normalization
#define SQRT_14 3.7416573867739413

// "You normalize a vector by dividing each of its components by its magnitude"

t_tuple result;
const t_tuple vectors[] = 		   {{4, 0, 0, VECTOR}, {1, 2, 3, VECTOR}};
const t_tuple expected_results[] = {{1, 0, 0, VECTOR}, {1 / SQRT_14, 2 / SQRT_14, 3 / SQRT_14, VECTOR}};

Test(suite_name, normalizing_vector_4_0_0) {
    normalize_vector(vectors[0], result);
    cr_expect_arr_eq(result, expected_results[0], sizeof(t_tuple));
}

Test(suite_name, normalizing_vector_1_2_3) {
    normalize_vector(vectors[1], result);
    cr_expect_arr_eq(result, expected_results[1], sizeof(t_tuple));
}

Test(suite_name, magnitude_of_normalized_vector_1_2_3) {
    normalize_vector(vectors[1], result);
    cr_expect_eq(vector_magnitude(result), 1);
}

Test(suite_name, normalization_of_zero_magnitude_vector_should_fail) {
	cr_expect_eq(normalize_vector((t_tuple){0, 0, 0, VECTOR}, result), -1);
}

Test(suite_name, normalization_of_point_should_fail) {
	cr_expect_eq(normalize_vector((t_tuple){1, 2, 3, POINT}, result), -1);
}
