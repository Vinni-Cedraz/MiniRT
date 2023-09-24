#include "tester.h"

#define suite_name float_tests

Test(suite_name, comparing_floating_point_numbers) {
	float a = 1.872;
	float b = 1.872;
	cr_expect_eq(1, compare_floats(a, b));
}
