#include "../../../tests/tester.h"

int main() {
	t_matrix half_quarter = create_x_rotation_matrix(M_PI/4);
	print_4x4matrix(half_quarter);
	t_matrix inverse_rotation = invert_matrix(half_quarter);
	print_4x4matrix(inverse_rotation);
}
