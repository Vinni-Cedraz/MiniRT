#include "tester.h"

#define suite_name basic_tuple_operations

t_tuple result;

const t_tuple
	tuples_a[] = {{1.2,2.4,3.5,POINT}, {3.1,2.1,1.1,POINT}, {3.1,2.1,1.1,POINT}, {3,2,1,VECTOR}, {1, 2, -3, -4}, {1, -2, 3, -4}, {2, 6, 3, 5}},
	tuples_b[] = {{1.2,2.4,3.5,VECTOR},{5.1,6.1,7.1,POINT}, {5.1,6.1,7.1,VECTOR},{5,6,7,VECTOR},},
	expected[] = {{2.4,4.8,7.0,POINT}, {-2, -4, -6, VECTOR},{-2,-4,-6,POINT},    {-2,-4,-6,VECTOR},{-1, -2, 3, 4},{3.5,-7,10.5,-14}, {1, 3, 1.5, 2.5}};

Test(suite_name, adding_two_tuples) {
    add_tuples(tuples_a[0], tuples_b[0], result);
	tuples_eq(result, expected[0]);
}

Test(suite_name, subtracting_two_points) {
    subtract_tuples(tuples_a[1], tuples_b[1], result);
	tuples_eq(result, expected[1]);
}

Test(suite_name, subtracting_vector_from_point) {
	subtract_tuples(tuples_a[2], tuples_b[2], result);
	tuples_eq(result, expected[2]);
}

Test(suite_name, subtracting_two_vectors) {
	subtract_tuples(tuples_a[3], tuples_b[3], result);
	tuples_eq(result, expected[3]);
}

Test(suite_name, negating_a_tuple) {
	negate_tuple(tuples_a[4], result);
	tuples_eq(result, expected[4]);
}

Test(suite_name, multiplying_a_tuple_by_a_scalar) {
	multiply_tuple_by_scalar(tuples_a[5], 3.5, result);
	tuples_eq(result, expected[5]);
}

Test(suite_name, multiplying_a_tuple_by_a_fraction) {
	multiply_tuple_by_scalar(tuples_a[6], 0.5, result);
	tuples_eq(result, expected[6]);
}
