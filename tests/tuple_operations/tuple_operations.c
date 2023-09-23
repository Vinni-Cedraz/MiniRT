#include "../tester.h"
#include "../../src/tuple_operations.c"

#define suite_name tuple_operations
#define test1_description CYAN"checks if two tuples are being added correctly"RESET
#define test2_description CYAN"checks if two tuples are being subtracted correctly"RESET
#define test3_description CYAN"checks if the values of a duple are each being inverted"RESET

Test(suite_name, adding_two_tuples, .description = test1_description) {
	t_tuple a = {1.2, 2.4, 3.5, 0};
	t_tuple b = {1.2, 2.4, 3.5, 1};
	t_tuple result = {0, 0, 0, 0};
	t_tuple expected_result = {2.4, 4.8, 7.0, 1};

	add_tuples(a, b, result);
	cr_expect_arr_eq(result, expected_result, sizeof(t_tuple));
}
