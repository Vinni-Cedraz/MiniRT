#include <criterion/criterion.h>
#include "../../src/create_tuples.c"
#include "../tester.h"

#define suite_name tuples
#define test1_description CYAN"shows that a tuple is a point when w is 1, and its xyz are correct"RESET
#define test2_description CYAN"shows that a tuple is a vector when w is 0, and its xyz are correct"RESET
#define test3_description CYAN"see if we are comparing floats correctly"RESET

Test(suite_name, tuple_is_a_valid_point, .description = test1_description)
{
	t_tuple tuple = {1, 2, 6};

	create_a_point(tuple);
	cr_expect_eq(1, tuple[X]);
	cr_expect_eq(2, tuple[Y]);
	cr_expect_eq(6, tuple[Z]);
	cr_expect_eq(1, tuple[W]);
}

Test(suite_name, tuple_is_a_valid_vector, .description = test2_description)
{
	t_tuple tuple = {2, 3, 4};

	create_a_vector(tuple);
	cr_expect_eq(2, tuple[X]);
	cr_expect_eq(3, tuple[Y]);
	cr_expect_eq(4, tuple[Z]);
	cr_expect_eq(0, tuple[W]);
}
