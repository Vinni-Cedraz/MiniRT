#include "tester.h"

// Scenario : Multiplying a matrix by the identity matrix
# define scenario1 CYAN  \
		"\nGiven the following matrix A:\n" \
		"| 0 | 1 | 2 | 4 |\n" \
		"| 1 | 2 | 4 | 8 |\n" \
		"| 2 | 4 | 8 | 16 |\n" \
		"| 4 | 8 | 16 | 32 |\n" \
		"Then A * identity_matrix = A\n" \
		"Scenario : Multiplying the identity matrix by a tuple\n" \
		"Given a ← tuple(1, 2, 3, 4)\n" \
		"Then identity_matrix * a = a" RESET

Test(the_identity_matrix, Multiplying_by_identity, .description = scenario1) {

	t_matrix a = {
		{0, 1, 2, 4},
		{1, 2, 4, 8},
		{2, 4, 8, 16},
		{4, 8, 16, 32},
	};

	t_matrix res = mult_by_identity(a);
	cr_expect_eq(TRUE, matrices_eq(a, res));
}

