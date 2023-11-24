#include "tester.h"

void init_walls(t_plane walls[]) {
	if (&walls[0]) {
		set_transform((t_shape *)&walls[0], create_identity_matrix());
	}
}
