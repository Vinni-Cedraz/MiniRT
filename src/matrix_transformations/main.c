#include "translation.c"
#include "../../tests/tester.h"

int main(){
	t_tuple			p;
	t_matrix		translation_matrix;
	t_matrix		inverse_of_translation_matrix;
	t_tuple			result; 

	translation_matrix = translation((t_tuple){5, -3, 2, POINT});
	inverse_of_translation_matrix = invert_matrix(translation_matrix);
 	p[X] = -3, p[Y] = 4, p[Z] = 5, p[W] = POINT;
	printf(CYAN"translation matrix: \n"RESET);
	print_4x4matrix(translation_matrix);
	printf(CYAN"inverse matrix: \n"RESET);
	print_4x4matrix(inverse_of_translation_matrix);
	multiply_tuple_by_matrix(p, inverse_of_translation_matrix, result);
	printf(CYAN"result point: \n"RESET);
	print_tuple(result);
	printf(CYAN"expected point: \n"RESET);
	const t_tuple	expected = {-8, 7, 3, POINT};
	print_tuple(expected);
}
