#include "../../tests/tester.h"

int main() {
	t_world w = default_world();
	t_sphere *outer = &w.objs[0];
	t_sphere *inner = &w.objs[1];
	outer->material.ambient = 1;
	inner->material.ambient = 1;
	t_ray	r = create_ray((t_tuple){0, 0, 0.75, POINT}, (t_tuple){0, 0, -1, VECTOR});
	t_tuple color;

	color_at(&w, &r, color);
}
