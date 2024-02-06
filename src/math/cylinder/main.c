#include "../../../tests/tester.h"

#include <stdarg.h>

const t_tuple FROM = {0, 4, 25, POINT};
const int NUMBER_OF_OBJECTS = 2;

int main(void) {
    t_world world;
    t_cylinder cyl;
    t_sphere sphere;

    cyl = create_cylinder();
    sphere = create_sphere();
    cyl.closed = TRUE;
    // set_cyl_min_max(&cyl, -2, 2);

    t_matrix rotation = create_y_rotation_matrix(M_PI / 5);
    t_matrix translation_matrix = create_translation_matrix((t_tuple){5, 0, 0, POINT});

    world.light = &(t_point_light){
        .position = {-8, 7, 25, POINT},
        .intensity = {1, 1, 1, POINT},
    };
    set_transform((t_shape *)&cyl, chain_transformations((t_matrix *[]){&translation_matrix, &rotation, NULL}));
    create_test_world(&world, FROM, NUMBER_OF_OBJECTS, sphere, cyl);
}
