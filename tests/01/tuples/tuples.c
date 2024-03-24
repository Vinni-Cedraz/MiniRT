#include <criterion/criterion.h>
#include "tester.h"

#define suite_name tuples
#define test1_description CYAN"shows that a tuple is a point when w is 1, and its xyz are correct"RESET
#define test2_description CYAN"shows that a tuple is a vector when w is 0, and its xyz are correct"RESET
#define test3_description CYAN"see if we are comparing doubles correctly"RESET

Test(suite_name, tuple_is_a_valid_tuple, .description = test3_description)
{
	t_tuple a;

	a = create_tuple(4.3, -4.2, 3.1, 1);
	cr_expect_eq(a.x, 4.3);
	cr_expect_eq(a.y, -4.2);
	cr_expect_eq(a.z, 3.1);
	cr_expect_eq(a.w, 1);
}

// Test(suite_name, tuple_is_a_valid_point, .description = test1_description)
// {
// 	t_tuple tuple;
//
// 	create_point(tuple);
// 	cr_expect_eq(0, tuple[X]);
// 	cr_expect_eq(0, tuple[Y]);
// 	cr_expect_eq(0, tuple[Z]);
// 	cr_expect_eq(POINT, tuple[W]);
// }
//
// Test(suite_name, tuple_is_a_valid_vector, .description = test2_description)
// {
// 	t_tuple tuple;
//
// 	create_vector(tuple);
// 	cr_expect_eq(0, tuple[X]);
// 	cr_expect_eq(0, tuple[Y]);
// 	cr_expect_eq(0, tuple[Z]);
// 	cr_expect_eq(VECTOR, tuple[W]);
// }
