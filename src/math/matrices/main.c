#include "minirt.h"

int main () {
	t_matrix *a = create_4x4_matrix(&(t_matrix){
		{1,2,3,4},
		{5,6,7,8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}, {NULL}
	});
	t_matrix *b = create_4x4_matrix(&(t_matrix){
		{-2, 1, 2,3 },
		{3, 2, 1, -1},
		{4, 3, 6, 5},
		{1, 2, 7, 8}, {NULL}
	});
	t_matrix *expected = create_4x4_matrix(&(t_matrix){
		{20, 22, 50, 48},
		{44, 54, 114, 108},
		{40, 58, 110, 102},
		{16, 26, 46, 42}, {NULL}
	});
	t_matrix *result = mult_matrices(a , b);
	if (matrices_eq(*expected, *result) == TRUE)
		printf("the matrices are equal\n");
	else
		printf("unequal\n");

	printf("(outside) pointer:\n");
	print_tuple(result->rows[ROW1]);
	printf("(outside) not pointer:\n");
	print_tuple(result->row_1);

	printf("result matrix\n");
	print_4x4matrix(*result);
}
