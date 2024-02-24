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
	t_matrix a = create_4x4_matrix(&(t_matrix){
		{1,2,3,4},
		{5,6,7,8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	});
	t_matrix b = create_4x4_matrix(&(t_matrix){
		{-2, 1, 2,3 },
		{3, 2, 1, -1},
		{4, 3, 6, 5},
		{1, 2, 7, 8}
	});
	t_matrix expected = create_4x4_matrix(&(t_matrix){
		{20, 22, 50, 48},
		{44, 54, 114, 108},
		{40, 58, 110, 102},
		{16, 26, 46, 42}
	});
	t_matrix expected2 = create_4x4_matrix(&(t_matrix){
		{10, 11, 25, 24},
		{22, 27, 57, 54},
		{20, 29, 55, 51},
		{8, 13, 23, 21}
	});
	t_matrix result = mult_matrices(a , b);
	cr_assert_eq(matrices_eq(expected, result), TRUE);

	// checking if the result matrix is operational
	t_matrix result2 = create_identity_matrix();
	multiply_tuple_by_scalar(result.rows[ROW1], 0.5, result2.row_1);
	multiply_tuple_by_scalar(result.rows[ROW2], 0.5, result2.row_2);
	multiply_tuple_by_scalar(result.rows[ROW3], 0.5, result2.row_3);
	multiply_tuple_by_scalar(result.rows[ROW4], 0.5, result2.row_4);

	cr_assert_eq(matrices_eq(expected2, result2), TRUE);
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
	t_matrix A = create_4x4_matrix(&(t_matrix){
		{1, 2, 3, 4},
		{2, 4, 4, 2},
		{8, 6, 4, 1},
		{0, 0, 0, 1}
	});
	t_tuple b = {1, 2, 3, 1};
	t_tuple expected = {18, 24, 33, 1};
	t_tuple result;

	multiply_tuple_by_matrix(b, A, result);
	cr_assert_eq(tuples_eq(expected, result), TRUE);
}
