#include "../tests/tester.h"

int main() {
	t_cylinder cyl = create_cylinder();
	const t_ray r = {
		.origin = {0, 4, -2, POINT},
		.direction = {0, -1, 1, VECTOR}
	};

	cyl.closed = TRUE;
	set_cyl_min_max(&cyl, 1, 2);
	t_intersection xs = create_intersection(&cyl, r);
	printf("xs.count => %d\n", xs.count);
}
