#include "tester.h"

#define suite_name float_tests

Test(suite_name, comparing_equal_floats) {
    float a = 1.872;
    float b = 1.872;
    cr_expect_eq(TRUE, compare_floats(a, b));
}

Test(suite_name, comparing_unequal_floats) {
    float a = 1.872;
    float b = 0.872;
    cr_expect_eq(FALSE, compare_floats(a, b));
}

Test(suite_name, comparing_unequal_floats_below_one_above_zero) {
    float a = 0.972;
    float b = 0.872;
    cr_expect_eq(FALSE, compare_floats(a, b));
}

Test(suite_name, comparing_unequal_floats_pretty_close) {
    float a = 1.001;
    float b = 1.000;
    cr_expect_eq(FALSE, compare_floats(a, b));
}

Test(suite_name, comparing_unequal_floats_five_decimals,
     .description = CYAN "\nFive decimal places was the highest precision detected: "
                         "float_a(1.00001) != float_b(1.00000)") {
    float a = 1.00001;
    float b = 1.00000;
    cr_expect_eq(FALSE, compare_floats(a, b));
}

Test(suite_name, comparing_unequal_floats_six_decimals,
     .description = CYAN
     "\nThis one should give a false positive, float_a(1.000001) == float_b(1.000000)") {
    float a = 1.000001;
    float b = 1.000000;
    cr_expect_eq(TRUE, compare_floats(a, b));
}