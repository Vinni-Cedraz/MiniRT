#include "../../tester.h"

// Scenario : The default minimum and maximum for a cylinder
#define scenario1 CYAN             \
"\nGiven cyl ← cylinder()\n"       \
"Then cyl.minimum = -infinity\n"   \
"And cyl.maximum = infinity" RESET

Test(min_max_bounds, the_default_values, .description = scenario1) {
	t_shape cyl = create_cylinder();
	cr_expect_eq(doubles_eq(cyl.min, -INFINITY), TRUE);
	cr_expect_eq(doubles_eq(cyl.max, INFINITY), TRUE);
}
