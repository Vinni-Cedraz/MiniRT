#include <criterion/criterion.h>
#include "../../src/create_tuples.c"
#include "../tester.h"

#define suite_name tuples
#define test1_description CYAN"shows that a tuple is a point when w is 1, and its xyz are correct"RESET
#define test2_description CYAN"shows that a tuple is a vector when w is 0, and its xyz are correct"RESET
#define test3_description CYAN"see if we are comparing floats correctly"RESET

Test(suite_name, tuple_is_a_valid_point, .description = test1_description)
{
	t_tuple *tuple;

	tuple = malloc(sizeof(t_tuple));
	*tuple = (t_tuple){1, 2, 6};
	*tuple = create_a_point(tuple);
	cr_expect_eq(1, tuple->x);
	cr_expect_eq(2, tuple->y);
	cr_expect_eq(6, tuple->z);
	cr_expect_eq(1, tuple->w);
	free(tuple);
}

Test(suite_name, tuple_is_a_valid_vector, .description = test2_description)
{
	t_tuple tuple;

	tuple = create_a_vector(&(t_tuple){2, 3, 4});
	cr_expect_eq(2, tuple.x);
	cr_expect_eq(3, tuple.y);
	cr_expect_eq(4, tuple.z);
	cr_expect_eq(0, tuple.w);
}
