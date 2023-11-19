#include "../../tests/tester.h"

int main() {
	const t_ray r = create_ray((t_tuple){0, 4, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	const t_sphere s = create_sphere();
	const t_intersection intersect = create_intersection((void *)&s, r);

// #include <assert.h>
	printf("count %d\n", intersect.count);
	printf("intersect.head->t => %f\n", intersect.head->t);
	printf("intersect.head->next->t => %f\n", intersect.head->next->t);
	// assert(intersect.count == 2);
	//
	// assert(TRUE == floats_eq(intersect.head->t, 4.0));
	// assert(TRUE == floats_eq(intersect.head->next->t, 6.0));
}
