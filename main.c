#include "include/minirt.h"

int main () {
	t_tuple vec = subtract_tuples(create_point(0, 1, -2), create_point(0, 0, 0));
	print_tuple(normalize(vec));
}
