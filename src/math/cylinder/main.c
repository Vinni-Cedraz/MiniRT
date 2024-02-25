#include "../../../tests/tester.h"

t_tuple FROM = {0, 4, 25, POINT};
int NUMBER_OF_OBJECTS = 1;

int main(void) {
    t_world world;
    t_cylinder cyl;

    cyl = create_cylinder();
    cyl.closed = TRUE;
    set_cyl_min_max(&cyl, -1, 1);

 // 	t_matrix *rotation_z = create_z_rotation_matrix(M_PI / 3);
	// t_matrix *rotation_y = create_y_rotation_matrix(M_PI / 4);
	t_matrix *rotation_x = create_x_rotation_matrix(-M_PI / 4);

    world.light = &(t_point_light){
        .position = {-8, 7, 25, POINT},
        .intensity = {1, 1, 1, POINT},
    };
	set_transform((t_shape *)&cyl, rotation_x);
    // set_transform((t_shape *)&cyl, mult_matrices(rotation_z, rotation_y));
    create_test_world(&world, FROM, NUMBER_OF_OBJECTS, cyl);
}
