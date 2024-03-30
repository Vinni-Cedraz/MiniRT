#include "include/minirt.h"

int main() {
t_matrix A = { 
		.grid = { {1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1} }, 
		.size = 4
	};
	t_tuple b = {1, 2, 3, POINT};
	// t_tuple expected = {18, 24, 33, 1};

	t_tuple result = multiply_tuple_by_matrix((double[4]){b.x, b.y, b.z, b.w}, A, POINT);
	print_tuple(result);
}
