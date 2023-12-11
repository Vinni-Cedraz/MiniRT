#include "minirt.h"

int main() {
    t_world w;
    t_cylinder cyl = create_cylinder();

    set_cyl_min_max(&cyl, -2.5, 2.5);
    cyl.closed = TRUE;
    init_tuple((t_tuple){1, 0, 0, COLOR}, cyl.material.color);
    w.objs = malloc(sizeof(t_shape));
    w.objs[0] = *(t_shape *)&cyl;
    w.count = 1;

    w.light = &(t_point_light){
        {10, 25, 10, POINT},
        {1, 1, 1, COLOR},
    };

    quick_render(&w);
}
