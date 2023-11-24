#include "tester.h"

void init_floor(t_shape *floor) {
    set_material(
			(t_tuple){DEFAULT, DEFAULT, 0, DEFAULT},
			(t_tuple){1, 0.9, 0.9, COLOR},
			&floor->material
	);
}
