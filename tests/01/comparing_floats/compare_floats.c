#include "tester.h"

#define suite_name double_tests

Test(suite_name, comparing_equal_doubles) {
    double a = 1.872;
    double b = 1.872;
    cr_expect_eq(TRUE, doubles_eq(a, b));
}

Test(suite_name, comparing_unequal_doubles) {
    double a = 1.872;
    double b = 0.872;
    cr_expect_eq(FALSE, doubles_eq(a, b));
}

Test(suite_name, comparing_unequal_doubles_below_one_above_zero) {
    double a = 0.972;
    double b = 0.872;
    cr_expect_eq(FALSE, doubles_eq(a, b));
}

Test(suite_name, comparing_unequal_doubles_pretty_close) {
    double a = 1.001;
    double b = 1.000;
    cr_expect_eq(FALSE, doubles_eq(a, b));
}

Test(suite_name, comparing_unequal_doubles_five_decimals,
     .description = CYAN
     "\nThis one should give a false positive, double_a(1.000001) == double_b(1.000000)") {
    double a = 1.000001;
    double b = 1.000000;
    cr_expect_eq(TRUE, doubles_eq(a, b));
}
