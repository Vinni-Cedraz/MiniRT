#include "minirt.h"

int main() {
	t_world w;
	t_ray	r;
	t_intersection xs;

	w = default_world();
	r = create_ray((t_tuple){0, 0, -5, POINT},(t_tuple){0, 0, 1, VECTOR});
	xs = intersect_world_with_ray(&w, &r);
	printf("xs.count = %d\n", xs.count);
}
