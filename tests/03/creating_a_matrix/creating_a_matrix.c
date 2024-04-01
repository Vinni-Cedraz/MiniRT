#include "../../tester.h"
#include <criterion/internal/assert.h>
#include <stdio.h>

 // Scenario : Constructing and inspecting a 4x4 matrix
#define scenario1 	CYAN"\nGiven the following 4x4 matrix M:\n" \
						"| 1 | 2 | 3 | 4 |\n" \
						"| 5.5 | 6.5 | 7.5 | 8.5 |\n" \
						"| 9 | 10 | 11 | 12 |\n" \
						"| 13.5 | 14.5 | 15.5 | 16.5 |\n" \
						"Then M[0,0] = 1\n" \
						"And M[0,3] = 4\n" \
						"And M[1,0] = 5.5\n" \
						"And M[1,2] = 7.5\n" \
						"And M[2,2] = 11\n" \
						"And M[3,0] = 13.5\n" \
						"And M[3,2] = 15.5" RESET

Test(creating_a_matrix, 4x4matrix, .description = scenario1) {
	t_matrix matrix = create_matrix((arr_mat){
		1, 2, 3, 4,
		5.5, 6.5, 7.5, 8.5,
		9, 10, 11, 12,
		13.5, 14.5, 15.5, 16.5,
	});

	cr_expect_eq(matrix.size, 4);
	cr_expect_eq(_determinant(matrix), -296);
}

 // Scenario : Constructing and inspecting a 4x4 matrix
#define scenario2 CYAN  \
				"Given the following 2x2 matrix M:\n" \
				"| -3 | 5 |\n" \
				"| 1 | -2 |\n" \
				"Then M[0,0] = -3\n" \
				"And M[0,1] = 5\n" \
				"And M[1,0] = 1\n" \
				"And M[1,1] = -2" RESET

Test(creating_a_matrix, _2x2matrix, .description = scenario2) {
	t_matrix matrix = create_matrix((arr_mat){
		-3, 5,
		1, 5,
	});

	cr_expect_eq(matrix.size, 2);
	cr_expect_eq(_determinant(matrix), -20);
}

 // Scenario : Constructing and inspecting a 4x4 matrix
#define scenario3 CYAN  \
				"Given the following 2x2 matrix M:\n" \
				"| -3 | 5 | 0 | \n" \
				"| 1 | -2 | 7 | \n" \
				"| 0 | 1 | 1 | \n" \
				"Then M[0,0] = -3\n" \
				"And M[0,1] = 5\n" \
				"And M[1,0] = 1\n" \
				"And M[1,1] = -2\n" \
				"And M[2,2] = 1" RESET

Test(creating_a_matrix, _3x3matrix, .description = scenario3) {
	t_matrix matrix = create_matrix((arr_mat){
		-3, 5, 0,
		1, -2, 7,
		0, 1, 1,
	});

	cr_expect_eq(matrix.size, 3);
	cr_expect_eq(_determinant(matrix), 22);
}

// Scenario4: Matrix equality with identical matrices"
#define scenario4 CYAN  \
				"Given the following matrix A:\n"             \
				"| 1 | 2 | 3 | 4 |\n"                         \
				"| 5 | 6 | 7 | 8 |\n"                         \
				"| 9 | 8 | 7 | 6 |\n"                         \
				"| 5 | 4 | 3 | 2 |\n"                         \
				"And the following matrix B:\n"               \
				"| 1 | 2 | 3 | 4 |\n"                         \
				"| 5 | 6 | 7 | 8 |\n"                         \
				"| 9 | 8 | 7 | 6 |\n"                         \
				"| 5 | 4 | 3 | 2 |\n"                         \
				"Then A = B\n"     RESET

// Scenario5: Matrix equality with different matrices\n"
#define scenario5 CYAN										  \
				"Given the following matrix A:\n"             \
				"| 1 | 2 | 3 | 4 |\n"                         \
				"| 5 | 6 | 7 | 8 |\n"                         \
				"| 9 | 8 | 7 | 6 |\n"                         \
				"| 5 | 4 | 3 | 2 |\n"                         \
				"And the following matrix B:\n"               \
				"| 2 | 3 | 4 | 5 |\n"                         \
				"| 6 | 7 | 8 | 9 |\n"                         \
				"| 8 | 7 | 6 | 5 |\n"                         \
				"| 4 | 3 | 2 | 1 |\n"                         \
				"Then A != B" RESET

Test(matrix_equality, _4x4identical_matrices, .description = scenario4) {
	t_matrix matrix_a = create_matrix((arr_mat){
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 8, 7, 6,
		5, 4, 3, 2
	});
	t_matrix matrix_b = create_matrix((arr_mat){
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 8, 7, 6,
		5, 4, 3, 2
	});
	cr_expect_eq(matrix_a.size, 4);
	cr_expect_eq(matrix_b.size, 4);
	matrices_eq(matrix_a, matrix_b);
}

Test(matrix_equality, _4x4different_matrices, .description = scenario5) {
	t_matrix matrix_a = create_matrix((arr_mat){
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 8, 7, 6,
		5, 4, 3, 2
	});
	t_matrix matrix_b = create_matrix((arr_mat){
		2, 3, 4, 5,
		6, 7, 8, 9,
		8, 7, 6, 5,
		4, 3, 2, 1
	});
	cr_expect_eq(matrix_a.size, 4);
	cr_expect_eq(matrix_b.size, 4);
	matrices_eq(matrix_a, matrix_b);
}
