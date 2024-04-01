#include "minirt.h"

int main() {
	t_matrix matrix = create_matrix((double []){
		1, 2, 3, 4,
		5.5, 6.5, 7.5, 8.5,
		9, 10, 11, 12,
		13.5, 14.5, 15.5, 16.5,
		END_MATRIX
	});

	printf("%d\n", matrix.size);
}
