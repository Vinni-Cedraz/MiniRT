#include "../../../tests/tester.h"

const t_tuple FROM = {0, 4, 25, POINT};
const int NUMBER_OF_OBJECTS = 1;

int main(void) {
    t_world world;
	// t_sphere s = create_sphere();
    t_cylinder cyl;

    cyl = create_cylinder();
    cyl.closed = TRUE;
    set_cyl_min_max(&cyl, -1, 1);

    t_matrix rotation_z = create_z_rotation_matrix(M_PI / 3);
	t_matrix rotation_y = create_y_rotation_matrix(M_PI / 4);
	// t_matrix rotation_x = create_x_rotation_matrix(-M_PI / 10);

    world.light = &(t_point_light){
        .position = {-8, 7, 25, POINT},
        .intensity = {1, 1, 1, POINT},
    };
	// set_transform((t_shape *)&s, create_scaling_matrix(2, 2, 2));
    set_transform((t_shape *)&cyl, chain_transformations((t_matrix *[]){&rotation_y, &rotation_z, NULL}));
    create_test_world(&world, FROM, NUMBER_OF_OBJECTS, cyl);
}


