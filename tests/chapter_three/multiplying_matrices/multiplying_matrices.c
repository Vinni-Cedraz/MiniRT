#include "tester.h"
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

// Scenario : Multiplying two matrices
#define scenario1                                                              \
  CYAN "\nGiven the following matrix A:\n"                                       \
       "| 1 | 2 | 3 | 4 |\n"                                                   \
       "| 5 | 6 | 7 | 8 |\n"                                                   \
       "| 9 | 8 | 7 | 6 |\n"                                                   \
       "| 5 | 4 | 3 | 2 |\n"                                                   \
       "And the following matrix B:\n"                                         \
       "| -2 | 1 | 2 | 3 |\n"                                                  \
       "| 3 | 2 | 1 | -1 |\n"                                                  \
       "| 4 | 3 | 6 | 5 |\n"                                                   \
       "| 1 | 2 | 7 | 8 |\n"                                                   \
       "Then A * B is the following 4x4 matrix:\n"                             \
       "| 20| 22 | 50 | 48 |\n"                                                \
       "| 44| 54 | 114 | 108 |\n"                                              \
       "| 40| 58 | 110 | 102 |\n"                                              \
       "| 16| 26 | 46 | 42 |"

Test(multiplying_matrices, multiplying_two_matrices, .description = scenario1) {

	t_matrix a = {
		{1,2,3,4},
		{5,6,7,8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	t_matrix b = {
		{-2, 1, 2,3 },
		{3, 2, 1, -1},
		{4, 3, 6, 5},
		{1, 2, 7, 8}
	};
	t_matrix expected = {
		{20, 22, 50, 48},
		{44, 54, 114, 108},
		{40, 58, 110, 102},
		{16, 26, 46, 42}
	};

	t_matrix result = mult_matrices(a , b);
	cr_assert_eq(matrices_eq(expected, result), TRUE);

}
