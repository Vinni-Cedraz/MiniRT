#include "../../src/tuple_operations.c"
#include "../tester.h"
#include <stdio.h>

#define suite_name tuple_operations

t_tuple a;
t_tuple b;
t_tuple result = {0, 0, 0, 0};
t_tuple expected;

void init_testing_tuples(void) {
    static int call_counter;
    t_tuple arr_a[] = { {2.2, 2.4, 3.5, POINT}, {3.2, 2.1, 1.1, POINT}, {3.2, 2.1, 1.1, POINT}},
			arr_b[] = { {1.2, 2.4, 3.5, VECTOR}, {5.1, 6.1, 7.1, POINT},{5.1, 6.1, 7.1, VECTOR}},
			arr_c[] = { {2.4, 4.8, 7.0, POINT},  {-2, -4, -6,   VECTOR},{-2, -4, -6, POINT}};

    for (int i = 0; i < 4; i++) {
		a[call_counter] = arr_a[call_counter][i];
		b[call_counter] = arr_b[call_counter][i];
        expected[call_counter] = arr_c[call_counter][i];
	}
    call_counter++;
}

Test(suite_name, adding_two_tuples, .init = init_testing_tuples) {
    add_tuples(a, b, result);
    cr_expect_arr_eq(result, expected, sizeof(t_tuple));
}

Test(suite_name, subtracting_two_points, .init = init_testing_tuples) {
    subtract_tuples(a, b, result);
    cr_expect_arr_eq(result, expected, sizeof(t_tuple));
}

Test(suite_name, subtracting_vector_from_point, .init = init_testing_tuples) {
	subtract_tuples(a, b, result);
    cr_expect_arr_eq(result, expected, sizeof(t_tuple));
}

// Test(suite_name, subtracting_two_vectors, .init = init_testing_tuples) {
// }
