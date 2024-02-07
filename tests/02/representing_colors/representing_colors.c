#include "tester.h"

#define suite_name representing_colors

#define scenario CYAN "\nGiven c ← color(-0.5, 0.4, 1.7)\n" \
						 "Then color[R] = -0.5\n" \
						 " And color[G] = 0.4\n" \
						 " And color[B] = 1.7" RESET

Test(suite_name, colors_are_rgb_tuples, .description = scenario) {
	t_tuple color = {-0.5, 0.4, 1.7};

	cr_expect_eq(doubles_eq(color[R], -0.5), TRUE);
	cr_expect_eq(doubles_eq(color[G], 0.4), TRUE);
	cr_expect_eq(doubles_eq(color[B], 1.7), TRUE);
}
