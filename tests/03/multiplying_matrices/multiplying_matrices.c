#include "../../tester.h"
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
		.grid = {
			{1,2,3,4}, {5,6,7,8}, {9, 8, 7, 6}, {5, 4, 3, 2}
		}, .size = 4
	}; 
	t_matrix b = { .grid = { {-2, 1, 2, 3}, {3, 2, 1, -1}, {4, 3, 6, 5}, {1, 2, 7, 8}}, .size = 4 };
	t_matrix expected = { .grid = { {20, 22, 50, 48}, {44, 54, 114, 108}, {40, 58, 110, 102}, {16, 26, 46, 42} }, .size = 4 };

	t_matrix result = mult_matrices(a , b);
	print_matrix(result, 4);
	cr_assert_eq(matrices_eq(expected, result), TRUE);
}

#define scenario2 CYAN \
"\nGiven the following matrix A:\n"							   \
" 1 | 2 | 3 | 4 |\n"										   \
" 2 | 4 | 4 | 2 |\n"										   \
" 8 | 6 | 4 | 1 |\n"										   \
" 0 | 0 | 0 | 1 |\n"                                           \
" And tuple b = {1, 2, 3, 1}\n"                                \
" Then A * b = {18, 24, 33, 1}"RESET \

Test(multiplying_matrices, a_matrix_multiplied_by_a_tuple, .description = scenario2) {
	t_matrix A = { 
		.grid = { {1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1} }, 
		.size = 4
	};
	t_tuple b = {1, 2, 3, POINT};
	t_tuple expected = {18, 24, 33, 1};

	t_tuple result = multiply_tuple_by_matrix((double[4]){b.x, b.y, b.z, b.w}, A, POINT);
	print_tuple(result);
	cr_assert_eq(tuples_eq(expected, result), TRUE);
}
