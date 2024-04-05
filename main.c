#include "minirt.h"

int main () {
	t_sphere s = create_sphere();

	t_intersection i1 = intersection(2, &s);
	t_intersection i2 = intersection(1, &s);
	t_intersection i3 = intersection(-2, &s);
	const t_intersection *arr[] = {
		&i1, &i2, &i3, NULL
	};
	const t_intersection hit = _hit(arr);
	printf("%f\n", hit.t);
}
