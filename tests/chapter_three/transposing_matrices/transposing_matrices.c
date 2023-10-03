#include "minirt.h"
#include "tester.h"

//Scenario : Transposing a matrix

#define Scenario1 CYAN \
"\nGiven the following matrix A: \\n"                      \
"| 0 | 9 | 3 | 0 |\n"                      \
"| 9 | 8 | 0 | 8 |\n"                      \
"| 1 | 8 | 5 | 3 |\n"                      \
"| 0 | 0 | 5 | 8 |\n"                      \
"Then transpose(A) is the following matrix:\n"                      \
"| 0 | 9 | 1 | 0 |\n"                      \
"| 9 | 8 | 8 | 0 |\n"                      \
"| 3 | 0 | 5 | 5 |\n"                      \
"| 0 | 8 | 3 | 8 |"                      RESET

Test(transposing_matrices, transposing_a_matrix, .description = Scenario1) {
	t_matrix a = {
		{0, 9, 3, 0},
		{9,8,0,8},
		{1, 8, 5,3},
		{0,0,5,8}
	};
	t_matrix expected = {
		{0,9,1,0},
		{9,8,8,0},
		{3,0,5,5},
		{0,8,3,8}
	};
	t_matrix result;

	result = transpose_matrix(a);
	cr_expect_eq(TRUE, matrices_eq(result, expected));

}

