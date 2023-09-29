#include "tester.h"

#define suite_name color_operations

t_tuple result;
const t_tuple c_1[] = {{0.9, 0.6, 0.75, COLOR},  {0.2, 0.3, 0.4, COLOR}, {1, 0.2, 0.4, COLOR}};
const t_tuple c_2[] = {{0.7, 0.1, 0.25, COLOR}, {0.9, 1, 0.1, COLOR}};
const t_tuple expected[] = { {1.6, 0.7, 1.0,  COLOR}, {0.2, 0.5, 0.5,  COLOR}, {0.4, 0.6, 0.8,  COLOR}, {0.9, 0.2, 0.04, COLOR} };

// Scenario: Adding colors
#define scenario1        													\
  CYAN "\nGiven c1 ← color(0.9, 0.6, 0.75)\n"                               \
  	   " And  c2 ← color(0.7, 0.1, 0.25)\n"                                 \
       " Then c1 + c2 = color(1.6, 0.7, 1.0)" RESET
Test(suite_name, adding_colors, .description = scenario1) {
	add_tuples(*c_1, *c_2, result);
   	t_bool is_eq = cr_expect_tuple_eq(result, expected[0]);
	cr_expect_eq(is_eq, TRUE);
}

// Scenario: Subtracting colors
#define scenario2                                                            \
  CYAN "\nGiven c1 ← color(0.9, 0.6, 0.75)\n"                                \
       " And  c2 ← color(0.7, 0.1, 0.25)\n"                                  \
       " Then c1 - c2 = color(0.2, 0.5, 0.5)" RESET
Test(suite_name, subtracting_colors, .description = scenario2) {
	subtract_tuples(*c_1, *c_2, result);
   	t_bool is_eq = cr_expect_tuple_eq(result, expected[1]);
	cr_expect_eq(is_eq, TRUE);
}

// Scenario: Multiplying a color by a scalar
#define scenario3                                                            \
  CYAN "\nGiven c ← color(0.2, 0.3, 0.4)\n"                                  \
       "Then c * 2 = color(0.4, 0.6, 0.8)" RESET
Test(suite_name, multipying_color_by_scalar, .description = scenario3) {
	multiply_tuple_by_scalar(c_1[1], 2.0, result);
   	t_bool is_eq = cr_expect_tuple_eq(result, expected[2]);
	cr_expect_eq(is_eq, TRUE);
}

//Scenario: Multiplying colors
#define scenario4                                                            \
  CYAN "\nGiven c1 ← color(1, 0.2, 0.4)\n"                                   \
  " And  c2 ← color(0.9, 1, 0.1)\n"                                          \
  " Then c1 * c2 = color(0.9, 0.2, 0.04)" RESET
Test(suite_name, multipying_color_by_color, .description = scenario4) {
	multiply_colors(c_1[2], c_2[1], result);
   	t_bool is_eq = cr_expect_tuple_eq(result, expected[3]);
	cr_expect_eq(is_eq, TRUE);
}
